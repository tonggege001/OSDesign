#ifndef MEMINFOMODEL_H
#define MEMINFOMODEL_H


class MemInfoModel
{
public:
    int MemSize;
    int FreeMemSize;
    double Usage;
    int BufferSize;
    int CachedSize;
    int SwapSize;
    int FreeSwapSize;
    int PageTableSize;

public:
    MemInfoModel();

    void Update();

};

#endif // MEMINFOMODEL_H
