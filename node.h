//mismatched data links are allowed... May want to set off a flag when a mismatched link is set though
//should probably override the = operator to implement type checking for setters
//
//assignment to next should ad hoc assign to previous ... may want to implement those separately...

template<class T> class node{
    private:
    node** links;
    T data;
    int linksize;
    public:

    //initializers 
    node(int linkcount = 1);
    node(T initdata,int linkcount);
    //data accessors
    T& val();
    int linkcount(){return linksize;};
    //link accessors
    node<T>& next();
    node<T>& prev();
    node<T>& link(int i);
    //link setters
    void next(node<T>&);
    void prev(node<T>&);
    //exceptions
    class no_link{};
    //operator overloads
};



template<class T> node<T>::node(int linkcount){
    linksize = linkcount;
    links = new node*[linkcount];
}

template<class T> node<T>::node(T initdata, int linkcount){
    linksize = linkcount;
    links = new node*[linkcount];
    data = initdata;
}
template<class T> T& node<T>::val(){
    return data;
}

template<class T> node<T>& node<T>::next(){
    return *links[0];
}
template<class T> node<T>& node<T>::prev(){
    if(1 >= linksize)
        throw no_link();
    return *links[1];
}
template<class T> node<T>& node<T>::link(int i){
    if(i >= linksize)
        throw no_link();
    return *links[i];
}
// I believe having it take a node<T> will force it to only link to same data types....
template<class T> void node<T>::next(node<T>& next){
    if(next.linkcount()>=2){
        next.prev(*this);
    }
    links[0] = &next;
}
template<class T> void node<T>::prev(node<T>& next){
    if(linkcount()<=1)
        throw no_link();
    links[1] = &next;
}
