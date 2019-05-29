## Mano vector klasės realizacija

Šioje repozitorijoje galima rasti mano kurtą vektorių ir nuorodas į ekspermentiniams tyrimams skirtus projektus

- grow() ir push_back() int tyrimo projektas [čia](https://github.com/gitguuddd/Mkvector3/tree/obj_test)
- tyrimas jau dirbant su pilnais stud klasės objektais/push_back() tuščius [čia]( https://github.com/gitguuddd/Mkvector3/tree/obj_test_class)
- Šio branch'o cpp faile yra tik trumpas kodas, ištestuojantis mano vektoriaus funkcijas

## Vektoriuje realizuotos funkcijos
- visų pirma **typedefs**
```shell
typedef T* iterator;
typedef const T* c_iterator;
typedef T value_type;
typedef size_t size_type;
typedef T& reference;
typedef const T& c_reference;
typedef std::reverse_iterator<iterator> reverse_iterator;
typedef std::reverse_iterator<c_iterator > reverse_c_iterator;
```
**Constructors/Destructors/Rule Of Five**
```shell
Vector()
Vector(size_type n, c_reference val = T{})
Vector( Vector& v)
Vector(std::initializer_list<T> list)
Vector(const Vector& v)noexcept
Vector& operator=( const Vector& v)
Vector(Vector&& v)noexcept
Vector & operator=(Vector && v)noexcept
~Vector() { uncreate(); }
void assign(size_t n, c_reference val)
```
**Element access**
```shell
reference operator[](size_type i) 
c_reference operator[](size_type i) const 
reference at(size_type i)
c_reference at(size_type i) constž
reference front()
c_reference front()const 
reference back()
c_reference back() const
```
**Iterators**
```shell
iterator begin()
c_iterator cbegin() const 
iterator end() 
c_iterator cend() const 
reverse_iterator rbegin() 
reverse_c_iterator crbegin()
reverse_iterator rend() 
reverse_c_iterator crend()
```
**Capacity**
```shell
size_type size() const
size_type capacity() const
bool empty()const
void reserve(size_type n_cap)
void shrink_to_fit()
```
**Modifiers**
```shell
void push_back(c_reference val)
void clear()
void pop_back()
void swap(Vector & v)
void resize(size_type n, value_type val = T())
void erase(iterator i) 
void insert(iterator it, const T & val) 
```
**Operators**
```shell
bool operator==(const Vector<T>& lhs, const Vector<T>& rhs)
bool operator<(const Vector<T>& lhs, const Vector<T>& rhs)
bool operator!=(const Vector<T>& lhs, const Vector<T>& rhs)
bool operator>(const Vector<T>& lhs, const Vector<T>& rhs)
bool operator<=(const Vector<T>& lhs, const Vector<T>& rhs)
bool operator>=(const Vector<T>& lhs, const Vector<T>& rhs)
```
**Pagalbinės funkcijos**
```shell
void Vector<T>::create()
void Vector<T>::create(size_type n, c_reference val)
void Vector<T>::create(c_iterator a, c_iterator b)
void Vector<T>::uncreate()
void Vector<T>::grow()
void Vector<T>::unchecked_append(const T& val) 
```
## 5 Funkcijų aprašymai
**reserve(size_type n_cap)**
```shell
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
```
- Funkcija rezervuoja (padidina) vektoriaus capacity tam tikru skaičiumi ```n_cap```.Po naujos vietos allokavimo ir elementų perkopijavimo naudojant ```uncreate()``` sunaikinamas senasis objektas, jo rodyklės nukreipiamos į naujai alokuotą atmintį

**operator[]**
```shell
reference operator[](size_type i) {
        if(i>size()||i<0)throw std::out_of_range("operator[]: trying to access element at out of bounds index");
        return data[i]; }
```
- Funkcija gražina elemento, randamo ```i``` pozicijoje, reikšmę. Jei ```i``` indeksas yra už vektoriaus ribų iškviečiamas ```std_out_of_range``` exception`as

**shrink_to_fit()**
```shell
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
```
- Funkcija panaikina nereikalingai vektoriui rezervuotą atmintį ir sumažina vektoriaus ```max_size (talpą)``` iki vektoriaus ```v_size (dydžio)```. Jei ```v_size=0``` - objektas sunaikinamas.  

**swap(Vector & v)**
```shell
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
```
- Funkcija sukeičia dvieju vektorių rodykles vietomis

**clear()**
```shell
void clear()
    {
        iterator n_data = alloc.allocate(capacity());
        size_type cap = capacity();
        uncreate();
        max_size = n_data + cap;
        data = v_size = n_data;
    }
```
- Funkcija išvalo vektoriaus elementus bet nepakeičia vektoriui rezervuotos atminties dydžio

## Tyrimų benchmarkai

**grow()**
- Šio tyrimo metu buvo tiriama kiek kartų bus padidintas vektorius į jį push_backinant 100000000 elementų

|              | std::vector | vector.h |
|--------------|-------------|----------|
| growth_times | 28          | 28       |
- Iš lentelėje pavaizduotų tyrimo rezultatų galima įžvelgti tai, kad tiek ```std::vector```, tiek mano vektorius auga tuo pačiu tempu

**push_back int**
- Šio tyrimo metu buvo tiriamas laiko skirtumas tarp ```std::vector``` ir mano sukurto vektorius push_backinant 10000, 100000, 1000000, 10000000, 100000000 int elementų

|           | std::vector  | vector.h   |
|-----------|--------------|------------|
| 10000     | 0.000000 s.  | 0.000000 s |
| 100000    | 0.000997 s.  | 0.000000 s |
| 1000000   | 0.0069815 s. | 0.005984 s |
| 10000000  | 0.100730 s.  | 0.055717 s |
| 100000000 | 1.003318 s.  | 0.817813 s |
- Iš lentelėje pavaizduotų tyrimo rezultatų galima įžvelgti tai, kad mano sukurtas vektorius buvo gerokai greitesnis nei ```std::vector```
**push_back stud**
- Šio tyrimo metu buvo tiriamas laiko skirtumas tarp ```std::vector``` ir mano sukurto vektoriaus į juos push_backinant tuščius stud klasės objektus

|         | std::vector | vector.h   |
|---------|-------------|------------|
| 100     | 0.000000 s  | 0.000000 s |
| 1000    | 0.000891 s  | 0.001104 s |
| 10000   | 0.005985 s  | 0.007964 s |
| 100000  | 0.053807 s  | 0.055893 s |
| 1000000 | 0.521603 s  | 0.476723 s | 
- Iš lentelėje pavaidzuotų tyrimo rezultatų galima įžvelgti tai, kad ```std::vector``` yra spartesnis push_backinant mažesnį kiekį tuščių stud klasės objektų, bet mano vektorius paima viršų, kai objektų kiekis pasiekia milijoną

**Darbo programoje tyrimas**
- Šio tyrimo metu buvo tiriamas laiko skirtumas tarp ```std::vector``` ir mano sukurto vektoriaus jau dirbant su 1.5 ```Duomenų_apdorojimas_class``` versija

|         | std::vector | vector.h    |
|---------|-------------|-------------|
| 10      | 0.005984 s. | 0.00299 s.  |
| 100     | 0.005983 s. | 0.005985 s. |
| 1000    | 0.035904 s. | 0.04488 s.  |
| 10000   | 0.625327 s. | 0.367017 s. |
| 100000  | 5.22602 s.  | 3.448774 s. |
| 1000000 | 39.9777 s.  | 34.9615 s.  |
- Iš lentelėje pavaizduotų tyrimo rezultatų galima įžvelgti tai, kad mano sukurtas vektorius buvo greitesnis nei ```std::vector``` ir dirbant jau pagal galutinę paskirtį - saugant duomenis apie sutdentus

# Resume
- Taigi, ar verta naudoti mano vektorių? Ir taip ir ne. Nors mano vektorius kai kuriais atvejais yra greitesnis už ```stdd::vector``` , jis yra labai nestabilus, jis neturi iteratoriaus klasės - tokį vektorių yra tiesiog nepatogu vartoti + kad veiktų vektorius reikia naudoti -fpermissive flag :(


# Changelog

---
[v1.0](https://github.com/gitguuddd/Mkvector/releases/tag/v1.0) (2019-05-28)

**Pridėta**
- ```vector.h, vector.cpp, README.md```
-  Du branchai su ekspermintiam tyrimui skirtais projektais
