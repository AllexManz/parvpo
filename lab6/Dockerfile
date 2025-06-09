FROM ubuntu:22.04

RUN apt-get update && \
    apt-get install -y python3 python3-pip ragel gcc graphviz

WORKDIR /lab
COPY . .

# RUN ragel -C checker.rl
# RUN gcc checker.c -o checker
# RUN python3 generator.py

RUN ragel -C checker.rl

RUN ragel -V checker.rl > checker.dot && \
    dot -Tpng checker.dot -o checker.png

RUN gcc checker.c -o checker

CMD python3 generator.py && \
    [ -f checker.png ] && cp checker.png /output/ || echo "checker.png not found"


#    docker build -t haiku-generator .
#    docker run -it --rm haiku-generator
#    python3 generator.py
