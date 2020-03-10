# Get the GCC preinstalled image from Docker Hub
FROM gcc:4.9

WORKDIR /usr/src

RUN mkdir ./setup
RUN mkdir ./build
WORKDIR /usr/src/setup

RUN apt update
RUN apt install -y wget
RUN apt install -y glib2.0
RUN apt install -y darcs

RUN wget ftp://ftp.gnu.org/gnu/libtool/libtool-2.4.6.tar.gz
RUN tar xf libtool-2.4.6.tar.gz
RUN rm libtool-2.4.6.tar.gz
WORKDIR /usr/src/setup/libtool-2.4.6
RUN ./configure --prefix=/usr
RUN make
RUN make check
RUN make install

WORKDIR /usr/src/setup
RUN darcs clone http://gerris.dalembert.upmc.fr/darcs/gts-stable

WORKDIR /usr/src/setup/gts-stable
RUN sh autogen.sh
RUN make
RUN make install

WORKDIR /usr/src

RUN rm -R ./setup

RUN apt install -y libgtk-3-dev

# Copy the current folder which contains C++ source code to the Docker image under /usr/src
 
# Specify the working directory
# WORKDIR /usr/src/program

# RUN mkdir ./src
# RUN mkdir ./libs

# COPY ./libs.txt /usr/src/program/libs.txt
# COPY ./getlibs.sh /usr/src/program/getlibs.sh
# RUN bash ./getlibs.sh