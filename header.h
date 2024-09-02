#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
typedef struct Data
{
    int id;
    int time_wait;
    Data()
    {
        id = 0;
        time_wait = 0;
    }
} Data;

class struct_data
{
public:
    virtual int add_elem(Data) = 0;
    virtual Data delete_elem() = 0;
    virtual Data ndread() = 0;
    virtual bool Full() const = 0;
    virtual bool Empty() const = 0;
    virtual ~struct_data() {}
    int Getcurrent_length()
    {
        return current_length;
    }
protected:
    int current_length;
    int queuelength;
};


class List: public struct_data
{
public:
    List(List && ); //��
    List( List &  );//��������
    List & operator = ( List & ); //������
    List & operator = (List && ); //��
    List (int); //��
    List();//��
    ~List();//��
    int add_elem(Data );//��
    Data delete_elem();//��
    Data ndread();//��
    bool Full() const; //��
    bool Empty() const;//��
private:
    struct node
    {
        Data data;
        node* next;
    } *front, *tail;
};

class Massive: public struct_data
{
public:
    Massive( Massive && );//��
    Massive(Massive & );//��
    Massive & operator = ( Massive & );//��
    void operator = ( Massive && );//��
    Massive(int);//��
    ~Massive();//��
    int add_elem(Data );//��
    Data delete_elem();//��
    Data ndread();//��
    bool Full() const;//��
    bool Empty() const;//��
private:
    int front, tail;
    Data * inf;
};
#endif // HEADER_H_INCLUDED
