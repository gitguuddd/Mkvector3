//
// Created by Mindaugas K on 5/19/2019.
//

#ifndef MKVECTOR_VECTOR_H
#define MKVECTOR_VECTOR_H
#include<iostream>
#include<exception>
#include<iterator>
#include<memory>
template <class T>
class Vector{

public:

    typedef T* iterator;
    typedef const T* c_iterator;
    typedef T value_type;
    typedef size_t size_type;
    typedef T& reference;
    typedef const T& c_reference;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef std::reverse_iterator<c_iterator > reverse_c_iterator;


    // constructors
    explicit  Vector() { create(); }
    explicit Vector(size_type n, c_reference val = T{}) { create(n, val); }
    explicit Vector( Vector& v) { create(v.begin(), v.end()); }
    explicit Vector(std::initializer_list<T> list) {
        data = alloc.allocate(list.end() - list.begin());
        v_size = max_size= std::uninitialized_copy(list.begin(), list.end(), data);
    }
    Vector(const Vector& v)noexcept{
        create(v.begin(),v.end());
        v.uncreate();
    }
    Vector& operator=( const Vector& v){
        if(v==*this)return *this;
        uncreate();
        create(v.begin(),v.end());
        return *this;
    }
    Vector(Vector&& v)noexcept{
        create(v.begin(),v.end());
    v.uncreate();
    }
    Vector & operator=(Vector && v)noexcept{
        if(v==*this)return *this;
        uncreate();
        create(v.begin(),v.end());
        return *this;
    }
    ~Vector() { uncreate(); }
    void assign(size_t n, c_reference val) {
        clear();
        data = alloc.allocate(n);
        v_size = max_size = data + n;
        std::uninitialized_fill(data, v_size, val);
    }

    //element access
    reference operator[](size_type i) {
        if(i>size()||i<0)throw std::out_of_range("operator[]: trying to access element at out of bounds index");
        return data[i]; }
    c_reference operator[](size_type i) const {
        if(i>size()||i<0)throw std::out_of_range("operator[]: trying to access element at out of bounds index");
        return data[i]; }
    reference at(size_type i){
        if(i>size()||i<0)throw std::out_of_range("at: trying to access element at out of bounds index");
        return data[i];
    }
    c_reference at(size_type i) const{
        if(i>size()||i<0)throw std::out_of_range("at: trying to access element at out of bounds index");
        return data[i];
    }
    reference front(){
        return *data;
    }
    c_reference front()const {
        return *data;
    }
    reference back()
    {
        iterator temp = max_size;
        return *(--temp);
    }
    c_reference back() const
    {
        iterator temp = max_size;
        return *(--temp);
    }

    //capacity
    size_type size() const
    {
        return v_size - data;
    }
    size_type capacity() const
    {
        return max_size - data;
    }
    bool empty()const
    {
        return v_size-max_size==0;
    };
    void reserve(size_type n_cap)
    {
        if (n_cap > capacity())
        {
            iterator n_data = alloc.allocate(n_cap);
            iterator n_v_size = std::uninitialized_copy(data, v_size, n_data);
            uncreate();
            data = n_data;
             v_size = n_v_size;
             max_size = data + n_cap;
        }
    }
    void shrink_to_fit()
    {
        if(v_size<max_size)
        {
            size_type n_cap =v_size-data;
            iterator n_data = alloc.allocate(n_cap);
            iterator n_v_size = std::uninitialized_copy(data,v_size,n_data);
            uncreate();
            data=n_data;
            v_size=n_v_size;
            max_size=data+n_cap;
        }
        else if(v_size==0)
            uncreate();
    }

    //iterators
    iterator begin() { return data; }
    c_iterator cbegin() const { return data; }
    iterator end() { return v_size; }
    c_iterator cend() const { return v_size; }
    reverse_iterator rbegin() { return reverse_iterator(end()); }
    reverse_c_iterator crbegin() {return reverse_c_iterator(end());}
    reverse_iterator rend() { return reverse_iterator(begin()); }
    reverse_c_iterator crend() {return reverse_c_iterator(begin());}

    //modifiers
    void push_back(c_reference val)
    {
        if (max_size == v_size)
            grow();
        unchecked_append(val) ;
    }
    void clear()
    {
        iterator n_data = alloc.allocate(capacity());
        size_type cap = capacity();
        uncreate();
        max_size = n_data + cap;
        data = v_size = n_data;
    }
    void pop_back()
    {
        v_size -=1;
        alloc.destroy(v_size+1);
    }
    void swap(Vector & v) {
        iterator t_data = v.data;
        iterator t_v_size = v.v_size;
        iterator t_max_size = v.max_size;
        v.data = data;
        v.v_size = v_size;
        v.max_size = max_size;
        data= t_data;
        v_size = t_v_size;
        max_size = t_max_size;
    }
    void resize(size_type n, value_type val = T())
    {   if(n==0)
        uncreate();
        else if (n < size())
        {
            size_type new_size = n;
            iterator new_data = alloc.allocate(new_size);
            iterator new_v_size = std::uninitialized_copy(data, data + n, new_data);
            iterator new_max_size = new_data + n;

            uncreate();

            data = new_data;
            max_size = new_max_size;
            v_size =  new_v_size;
        }
        else if (n > size()) {
            size_type new_size = n;
            iterator new_data = alloc.allocate(new_size);
            iterator it = std::uninitialized_copy(data, v_size, new_data);
            std::uninitialized_fill(it, new_data + new_size - 1, val);
            iterator new_v_size = new_data + new_size;
            iterator new_max_size;
            if (capacity() < new_v_size - new_data) {
                new_max_size = new_v_size;
            } else {
                new_max_size = new_data + capacity();
            }
            uncreate();

            data = new_data;
            v_size = new_v_size;
            max_size = new_max_size;
        }
    }
    void erase(iterator i) {
        if (i < data || i >= v_size) throw std::out_of_range("erase: trying to access an element with out of bounds index");
        std::move(i + 1, v_size, i);
        v_size -= 1;
    }
    void insert(iterator it, const T & val) {
        if (it < data) throw std::out_of_range("insert: index is out of range");
        if (v_size == max_size) grow();
        v_size++;
        std::move(it, v_size, it + 1);
        *(it) = val;
    }


private:
    iterator v_size;
    iterator data;
    iterator max_size;
    std::allocator<T> alloc;
    void create() ;
    void create(size_type, c_reference);
    void create(c_iterator, c_iterator);
    void uncreate();
    void grow();
    void unchecked_append(c_reference);

};
template <class T> void Vector<T>::create() {
    data = max_size = v_size = nullptr;
}
template <class T> void Vector<T>::create(size_type n, c_reference val) {
    data = alloc.allocate(n);
    v_size = max_size = data + n;
    std::uninitialized_fill(data, v_size, val);
}
template <class T>
void Vector<T>::create(c_iterator a, c_iterator b) {
    data = alloc.allocate(b - a);
    v_size = max_size = std::uninitialized_copy(a, b, data);
}

template <class T> void Vector<T>::uncreate() {
    if (data) {
        iterator elem = v_size;
        while (elem != data)
            alloc.destroy(--elem);
        alloc.deallocate(data, max_size - data);
    }
    data = v_size = max_size = nullptr;
}
template <class T> void Vector<T>::grow() {
    size_type new_max_size = std::max(2 * (max_size - data), ptrdiff_t(1));
    iterator new_data = alloc.allocate(new_max_size);
    iterator new_v_size = std::uninitialized_copy(data, max_size, new_data);
    uncreate();
    data = new_data;
    v_size = new_v_size;
    max_size = data + new_max_size;
}
template <class T> void Vector<T>::unchecked_append(const T& val) {
    alloc.construct(v_size++, val);
}
template< class T>
bool operator==(const Vector<T>& lhs, const Vector<T>& rhs) {
    if (lhs.size() != rhs.size()) {
        return false;
    }
    for (int i = 0; i < lhs.size(); i++) {
        if (lhs.at(i) != rhs.at(i)) {
            return false;
        }
    }
    return true;
}
template< class T>
bool operator<(const Vector<T>& lhs, const Vector<T>& rhs) {
    return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}
template< class T>
bool operator!=(const Vector<T>& lhs, const Vector<T>& rhs) {
    return !(lhs == rhs);
}
template< class T>
bool operator>(const Vector<T>& lhs, const Vector<T>& rhs) {
    return rhs < lhs;
}
template< class T>
bool operator<=(const Vector<T>& lhs, const Vector<T>& rhs) {
    return !(rhs < lhs);
}
template< class T>
bool operator>=(const Vector<T>& lhs, const Vector<T>& rhs) {
    return !(lhs < rhs);
}

#endif //MKVECTOR_MKVECTOR_H
