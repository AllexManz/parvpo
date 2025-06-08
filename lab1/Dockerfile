FROM gcc:latest

WORKDIR /app

COPY . .

RUN g++ -o var1 base.cpp
RUN g++ -o var2 inline.cpp
RUN g++ -o var4 foreign.cpp functions/functions.cpp
RUN g++ -c foreign.cpp
RUN g++ -c functions/functions.cpp
RUN g++ -o var3 foreign.o functions.o

ENTRYPOINT ["/bin/sh", "-c", "./var1 && ./var2 && ./var3 && ./var4"]

#   docker build -t my_cpp_app .
#   docker run -it my_cpp_app
#   docker rmi my_cpp_app
