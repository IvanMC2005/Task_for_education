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
    List(List && ); //ок
    List( List &  );//сгодитс€
    List & operator = ( List & ); //сойдет
    List & operator = (List && ); //ок
    List (int); //ок
    List();//ок
    ~List();//ок
    int add_elem(Data );//ок
    Data delete_elem();//ок
    Data ndread();//ок
    bool Full() const; //ок
    bool Empty() const;//ок
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
    Massive( Massive && );//ок
    Massive(Massive & );//ок
    Massive & operator = ( Massive & );//ок
    void operator = ( Massive && );//ок
    Massive(int);//ок
    ~Massive();//ок
    int add_elem(Data );//ок
    Data delete_elem();//ок
    Data ndread();//ок
    bool Full() const;//ок
    bool Empty() const;//ок
private:
    int front, tail;
    Data * inf;
};
#endif // HEADER_H_INCLUDED
