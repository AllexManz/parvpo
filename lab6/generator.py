import random
import subprocess

with open("dictionary.txt") as f:
    WORDS = f.read().splitlines()

def make_haiku(_):
    word_count = random.randint(3, 15)
    words = random.sample(WORDS, k=word_count)
    split_points = sorted(random.sample(range(1, word_count), k=2))

    parts = [
        words[:split_points[0]],
        words[split_points[0]:split_points[1]],
        words[split_points[1]:]
    ]

    return '\n'.join(' '.join(part).capitalize() for part in parts) + '\n\n'

def is_valid(haiku):
    result = subprocess.run(['./checker', haiku], capture_output=True, text=True)
    return result.returncode

def find_valid_haikus():
    target = 10000
    for count in range(target):
        current = make_haiku(count)
        if is_valid(current):
            separator = f'{"="*10} CORRECT HAIKU (i = {count}/{target}) {"="*(60 - len(str(count)) - len(str(target)))}'
            print(f"{separator}\n{current.strip()}")

if __name__ == "__main__":
    find_valid_haikus()