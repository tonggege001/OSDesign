#ifndef CPUINFOMODEL_H
#define CPUINFOMODEL_H


class CPUInfoModel
{
public:
    double  CPUUsage;   //CPU利用率
    double  CPUSpeed;   //CPU速度
    int     LogProceNum;    //逻辑处理器数目
    int     PhyProcNum;     //物理处理器和核心数目
    int     PhyCoreNum;     //物理核心数目
    int     ProcNum;        //进程数
    int     ProcMaxNum;     //最大进程数

private:
    long long     lastCpuTotal;
    long long     lastCpuIdle;
    long long     nowCpuTotal;
    long long     nowCpuIdle;


public:
    CPUInfoModel();
    void _update_cpu_usage();
    void _update_procmax();
    void _update_attr();
    void Update();
    long long GetCpuTotal();
    long long GetCpuIdle();
};

#endif // CPUINFOMODEL_H
