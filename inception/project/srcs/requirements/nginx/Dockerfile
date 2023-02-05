FROM	alpine:3.16

RUN	apk update && apk upgrade && apk add --no-cache nginx

EXPOSE	8080

CMD	["nginx", "-g", "daemon off;"]
