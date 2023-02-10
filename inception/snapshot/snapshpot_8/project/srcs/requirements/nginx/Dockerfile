FROM	alpine:3.16

RUN	apk update && apk upgrade && apk add openssl && apk add --no-cache nginx

RUN		mkdir -p /etc/nginx/ssl && \
		openssl req \
		-newkey rsa:4096 \
		-x509 \
		-sha256 \
		-days 365 \
		-nodes \
		-subj "/C=FR/ST=Paris/L=Paris/O=School42/CN=localhost" \
		-keyout /etc/nginx/ssl/nuxu.42.fr.key \
		-out /etc/nginx/ssl/nuxu.42.fr.crt

RUN		apk add openrc
RUN		rc-update add nginx default

EXPOSE	443

CMD	["nginx", "-g", "daemon off;"]
