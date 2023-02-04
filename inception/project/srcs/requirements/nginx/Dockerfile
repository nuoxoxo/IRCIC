FROM	alpine:3.16

RUN	apk update && apk upgrade && apk add --no-cache nginx

EXPOSE	4343

CMD	["nginx", "-g", "daemon off;"]
