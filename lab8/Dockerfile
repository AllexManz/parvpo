FROM gcc:latest

WORKDIR /usr/src/app

COPY main.cpp .

RUN g++ -O2 -fno-lto main.cpp -o main_O2_no_lto
RUN g++ -O2 -flto=auto main.cpp -o main_O2_thin_lto
RUN g++ -O2 -flto main.cpp -o main_O2_full_lto

RUN g++ -Oz -fno-lto main.cpp -o main_Oz_no_lto
RUN g++ -Oz -flto=auto main.cpp -o main_Oz_thin_lto
RUN g++ -Oz -flto main.cpp -o main_Oz_full_lto

# Запускаем все исполняемые файлы
ENTRYPOINT ["sh", "-c", "ls -lh; ./main_O2_no_lto O2_no_lto; ./main_O2_thin_lto O2_thin_lto; ./main_O2_full_lto O2_full_lto; ./main_Oz_no_lto Oz_no_lto; ./main_Oz_thin_lto Oz_thin_lto; ./main_Oz_full_lto Oz_full_lto"]
