FROM gcc:latest

WORKDIR /usr/src/app

COPY main.cpp .

RUN g++ main.cpp -o main
RUN g++ -O0 main.cpp -o main_O0
RUN g++ -Og main.cpp -o main_Og
RUN g++ -O1 main.cpp -o main_O1
RUN g++ -O2 main.cpp -o main_O2
RUN g++ -O3 main.cpp -o main_O3
RUN g++ -Ofast main.cpp -o main_Ofast
RUN g++ -Os main.cpp -o main_Os
RUN g++ -Oz main.cpp -o main_Oz

ENTRYPOINT ["sh", "-c", "ls -lh; ./main simple; ./main_O0 O0; ./main_Og Og; ./main_O1 O1; ./main_O2 O2; ./main_O3 O3; ./main_Ofast Ofast; ./main_Os Os; ./main_Oz Oz"]

#   docker build -t optimization-levels .
#   docker run -it optimization-levels
#   docker rmi optimization-levels
