import sqlite3
import string
from random import randint, choices
from time import time


TEXT_PATH = 'strings.txt'
DB_PATH = 'strings.db'


def timer(func):
    def wrapped(*args, reset=None, **kwargs):
        runs = 3
        duration = 0
        for _ in range(runs):
            if reset:
                reset()
            start = time()
            res = func(*args, **kwargs)
            duration += time() - start
        avg_time = duration / runs
        print(f"{func.__name__}: {avg_time:.4f}")
        return res, avg_time
    return wrapped


def make_random_str(length):
    chars = string.ascii_letters + string.digits
    return ''.join(choices(chars, k=length))

def generate_strings(total_mb, max_len):
    target_bytes = total_mb * 1024 * 1024
    current_bytes = 0
    result = []

    while current_bytes < target_bytes:
        s = make_random_str(randint(0, max_len))
        result.append(s)
        current_bytes += len(s) + len(str(len(s))) + 2

    return result


def init_file():
    open(TEXT_PATH, 'w').close()

@timer
def save_to_file(data):
    with open(TEXT_PATH, 'a') as f:
        for item in data:
            f.write(f'{len(item)}:{item}\n')

@timer
def load_from_file():
    with open(TEXT_PATH, 'r') as f:
        return [line.split(':') for line in f]

@timer
def search_in_file(text):
    with open(TEXT_PATH, 'r') as f:
        return [line.split(':') for line in f if text in line]


def init_db():
    conn = sqlite3.connect(DB_PATH)
    cur = conn.cursor()
    cur.execute('DROP TABLE IF EXISTS Strings')
    cur.execute('''
        CREATE TABLE Strings (
            length INTEGER,
            string TEXT
        )
    ''')
    conn.commit()
    conn.close()

@timer
def save_to_db(data):
    conn = sqlite3.connect(DB_PATH)
    cur = conn.cursor()
    cur.executemany('INSERT INTO Strings VALUES (?, ?)', [(len(s), s) for s in data])
    conn.commit()
    conn.close()

@timer
def load_from_db():
    conn = sqlite3.connect(DB_PATH)
    cur = conn.cursor()
    cur.execute('SELECT length, string FROM Strings')
    return cur.fetchall()

@timer
def search_in_db(text):
    conn = sqlite3.connect(DB_PATH)
    cur = conn.cursor()
    cur.execute('SELECT length, string FROM Strings WHERE string LIKE ?', (f'%{text}%',))
    return cur.fetchall()


def run_tests(k, size):
    print(f'\n=== k = {k} {"=" * 80}')
    strings_data = generate_strings(size, k)

    print('\nЗапись:')
    for i in range(3):
        if i % 2 == 0:
            save_to_file(strings_data, reset=init_file)
            save_to_db(strings_data, reset=init_db)
        else:
            save_to_db(strings_data, reset=init_db)
            save_to_file(strings_data, reset=init_file)

    print('\nЧтение:')
    for i in range(3):
        if i % 2 == 0:
            load_from_file()
            load_from_db()
        else:
            load_from_db()
            load_from_file()

    print('\nПоиск:')
    for i in range(3):
        if i % 2 == 0:
            search_in_file('abc')
            search_in_db('abc')
        else:
            search_in_db('abc')
            search_in_file('abc')


for params in [(10, 100), (1000, 1000), (100000, 2000)]:
    run_tests(*params)