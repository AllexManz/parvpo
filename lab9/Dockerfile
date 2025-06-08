FROM gcc:latest

WORKDIR /app

COPY *cpp .

RUN g++ -o main main.cpp && \
    g++ -o const_loop_border const_loop_border.cpp && \
    g++ -o const_all_vars const_all_vars.cpp && \
    g++ -O0 -o volatile_O0 volatile.cpp && \
    g++ -O1 -o volatile_O1 volatile.cpp && \
    g++ -O2 -o volatile_O2 volatile.cpp && \
    g++ -O3 -o volatile_O3 volatile.cpp && \
    g++ -Oz -o volatile_Oz volatile.cpp && \
    g++ -O3 -o heavy_calcs heavy_calcs.cpp && \
    g++ -O3 -o heavy_calcs_volatile heavy_calcs_volatile.cpp

ENTRYPOINT [\
    "sh", "-c", \
    "./main main; ./const_loop_border const_loop_border; \
    ./const_all_vars const_all_vars; \
    ./volatile_O0 volatile_O0; ./volatile_O1 volatile_O1; ./volatile_O2 volatile_O2; ./volatile_O3 volatile_O3; ./volatile_Oz volatile_Oz; \
    ./heavy_calcs heavy_calcs; ./heavy_calcs_volatile heavy_calcs_volatile" \
]

#    docker build -t my-cpp-app .
#    docker run -it my-cpp-app
