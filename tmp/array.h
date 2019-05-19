#ifndef ARRAY_H
#define ARRAY_H


class ARRAY
{
    int *A;
    int SIZE;
public:
    ARRAY(int size);
    ~ARRAY();
    void set_SIZE(int size){SIZE = size;}
    void generate();
    int out_elem(int index){return A[index];}
    int out_size(){return SIZE;}
    void getArr(int *&B);
};

#endif // ARRAY_H
