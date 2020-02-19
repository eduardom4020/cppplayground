# Get the GCC preinstalled image from Docker Hub
FROM gcc:4.9
 
LABEL Name=cppdocker Version=0.0.1

# Copy the current folder which contains C++ source code to the Docker image under /usr/src
COPY ./src /usr/src/program
 
# Specify the working directory
WORKDIR /usr/src/program
 
# Use GCC to compile the main.cpp source file
RUN g++ -o main main.cpp
 
# Run the program output from the previous step
CMD ["./main"]