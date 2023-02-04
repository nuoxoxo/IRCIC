---
version: '3'

services:
  nginx:
    image: nginx:stable-alpine
    volumes:
      - ./public:/var/www/public
      - ./nginx/conf.d:/etc/nginx/conf.d/
    restart: unless-stopped
    ports:
      - "80:80"
    container_name: simple_nginx_html
---

###### \*parsing a yaml metadata block at the top of the md (where --- is used as delim) as a table
