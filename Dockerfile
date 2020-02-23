# Get the GCC preinstalled image from Docker Hub
FROM gcc:4.9

RUN apt-get update
RUN apt-get install -y wget

# Copy the current folder which contains C++ source code to the Docker image under /usr/src
COPY ./src /usr/src/program
COPY ./getlibs.sh /usr/src/program/getlibs.sh
COPY ./libs.txt /usr/src/program/libs.txt
 
# Specify the working directory
WORKDIR /usr/src/program

RUN mkdir ./libs
RUN bash ./getlibs.sh

RUN rm ./getlibs.sh ./libs.txt