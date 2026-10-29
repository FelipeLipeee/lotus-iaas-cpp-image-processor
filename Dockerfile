FROM ubuntu:22.04

RUN apt-get update && apt-get install -y g++

ENV PORT=8080
ENV AMBIENTE=producao

WORKDIR /app
COPY main.cpp .

RUN g++ main.cpp -o app

EXPOSE 8080
CMD ["./app"]
