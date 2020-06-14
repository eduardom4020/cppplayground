FROM gcc:4.9

RUN curl -sL https://deb.nodesource.com/setup_12.x | bash -
RUN apt-get install -y nodejs

RUN mkdir /convex_hull_project
WORKDIR /convex_hull_project
COPY . /convex_hull_project
RUN npm install

CMD npm start