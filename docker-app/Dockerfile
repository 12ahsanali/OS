FROM node:lts-alpine3.23

COPY index.js .

COPY public ./public

COPY package.json .

RUN npm i 

CMD  ["node" , "index.js"]