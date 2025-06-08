FROM gcc:latest

WORKDIR /app

COPY *cpp .

RUN g++ -O0 -o main_O0 main.cpp
RUN g++ -O1 -o main_O1 main.cpp
RUN g++ -O2 -o main_O2 main.cpp
RUN g++ -O3 -o main_O3 main.cpp
RUN g++ -Oz -o main_Oz main.cpp

RUN g++ -O0 -o macros_O0 macros.cpp
RUN g++ -O1 -o macros_O1 macros.cpp
RUN g++ -O2 -o macros_O2 macros.cpp
RUN g++ -O3 -o macros_O3 macros.cpp
RUN g++ -Oz -o macros_Oz macros.cpp

RUN g++ -O0 -o wrong_macros_O0 wrong_macros.cpp
RUN g++ -O1 -o wrong_macros_O1 wrong_macros.cpp
RUN g++ -O2 -o wrong_macros_O2 wrong_macros.cpp
RUN g++ -O3 -o wrong_macros_O3 wrong_macros.cpp
RUN g++ -Oz -o wrong_macros_Oz wrong_macros.cpp

ENTRYPOINT [\
    "sh", "-c", \
    "./main_O0 main_O0; \
    ./main_O1 main_O1; \
    ./main_O2 main_O2; \
    ./main_O3 main_O3; \
    ./main_Oz main_Oz; \
    ./macros_O0 macros_O0; \
    ./macros_O1 macros_O1; \
    ./macros_O2 macros_O2; \
    ./macros_O3 macros_O3; \
    ./macros_Oz macros_Oz; \
    ./wrong_macros_O0 wrong_macros_O0; \
    ./wrong_macros_O1 wrong_macros_O1; \
    ./wrong_macros_O2 wrong_macros_O2; \
    ./wrong_macros_O3 wrong_macros_O3; \
    ./wrong_macros_Oz wrong_macros_Oz" \
]

#    docker build -t my-cpp-app .
#    docker run -it my-cpp-app
