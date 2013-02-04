template<class T> class node{
    private:
    node** links;
    T data;
    int linksize;
    public:

    //initializers 
    node(int linkcount = 1);
    node(T initdata,int linkcount = 1);
    //link accessors
    node& next();
    node& prev();
    node& link(int i);
    //exceptions;
    class no_link{};

    
};



template<class T> node<T>::node(int linkcount){
    linksize = linkcount;
    links = new (node*)[linkcount];
}

template<class T> node<T>::node(T initdata, int linkcount){
    linksize = linkcount;
    links = new (node*)[linkcount];
    T = initdata;
}
template<class T> node& node<T>::next(){
    return *links[0];
}
template<class T> node& node<T>::prev(){
    if(1 >= linksize)
        throw no_link();
    return *links[1];
}
template<class T> node& node<T>::link(int i){
    if(i >= linksize)
        throw no_link();
    return *links[i];
}
