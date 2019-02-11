#ifndef NETINFOMODEL_H
#define NETINFOMODEL_H

#include <QString>

class NetInfoModel
{
public:
    double TimeScale;
    double DownloadSpeed;
    double UploadSpeed;
    QString IPv6;
    int ErrorNum;
    int TCPEstab;
    double UDPDatagramSpeed;

private:
    int lastDownload;
    int nowDownload;
    int lastUpload;
    int nowUpload;
    int lastUDP;
    int nowUDP;

public:
    NetInfoModel();
    void _update_dev();
    void _update_IP();
    void _update_snmp();
    void Update();
};

#endif // NETINFOMODEL_H
