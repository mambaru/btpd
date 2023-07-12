FROM debian
ENV LANG ru_RU.UTF-8
ENV TZ="Europe/Moscow"

COPY binaries/btpd /usr/local/bin/
RUN apt update  && apt install  -y libsnappy1v5
RUN groupadd -g 80 www \
    && useradd -u 30 --shell /sbin/nologin --group www wwwrun;
USER wwwrun
 
