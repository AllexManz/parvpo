%%{
    machine haiku_checker;
    alphtype unsigned char;

    action inc_syllable {
        // Используем битовую маску для проверки гласных (включая 'y')
        static const char vowel_mask[] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0,
            0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0,
            0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0,
            0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0
        };
        syllable_count += vowel_mask[(unsigned char)*p];
    }

    action check_line1 {
        if (syllable_count != 5) fgoto fail;
        syllable_count = 0;
        fnext line2_start;
    }

    action check_line2 {
        if (syllable_count != 7) fgoto fail;
        syllable_count = 0;
        fnext line3_start;
    }

    action check_line3 {
        if (syllable_count != 5) fgoto fail;
        fnext success;
    }

    # Основные паттерны
    vowel = [aeiouyAEIOUY] @inc_syllable;
    non_vowel = [^aeiouyAEIOUY];

    line1 = (vowel | non_vowel)* '\n' @check_line1;
    line2_start := (vowel | non_vowel)* '\n' @check_line2;
    line3_start := (vowel | non_vowel)* '\n' @check_line3;

    success := any* @{ return 1; };
    fail := any* @{ return 0; };

    main := line1;
}%%

%%{
    write data;
}%%

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check_haiku(const char *data, int length) {
    int cs = 0;
    const char *p = data;
    const char *pe = data + length;
    int syllable_count = 0;

    %% write init;
    %% write exec;

    return 0; // Если не достигли success, возвращаем 0
}

int main(int argc, char **argv) {
    const char* test_input = NULL;
    int length = 0;

    if (argc > 1) {
        test_input = argv[1];
        length = strlen(test_input);
    } else {
        // Чтение из stdin
        static char buffer[1024];
        length = fread(buffer, 1, sizeof(buffer), stdin);
        test_input = buffer;
    }

    // Проверяем, что ввод заканчивается двумя переносами строки
    if (length < 2 || test_input[length-1] != '\n' || test_input[length-2] != '\n') {
        fprintf(stderr, "Input must end with two newlines\n");
        return 0;
    }

    return check_haiku(test_input, length);
}