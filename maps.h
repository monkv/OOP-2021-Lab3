#pragma once
#include "product.h"
#include <iostream>
#include "vector"
#include "maps.h"

template<typename F, typename S>
class iterator {
private:
    std::pair<F, S>* it;
public:
    /**
     * конструктор итератора от указателя на на элемент мэпа
     * @param ptr
     */
    explicit iterator<F, S>(std::pair<F, S> *ptr): it(ptr) {}
    /**
     * копирующий конструктор
     * @param ptr итератор который нужно скопировать
     */
    iterator<F, S>(const iterator<F, S> &ptr) = default;
    /**
     * деструктор
     */
    ~iterator() = default;
    /**
     * перегрузка оператора префиксного инкремента
     * @return ссылку на итератор след ячейки
     */
    iterator<F, S>& operator ++() {
        it++;
        return *this;
    }
    /**
     * перегрузка оператора постфиксного инкремента
     * @return копию итератора до изменений
     */
    iterator<F, S> operator ++(int) {
        iterator<F, S> tmp(*this);
        ++(*this);
        return tmp;
    }
    /**
     * перегруженный оператор присваивания
     * @param сp объект который присвоим
     * @return ссылку на текущий объект
     */
    iterator<F, S>& operator = (const iterator<F, S> &cp) {
        if (this == &cp)
            return *this;
        it = cp.it;
        return *this;
    };
    /**
     * перегруженный оператор '*'
     * @return ссылку на элемент мэпа на котороую указывает итератор
     */
    std::pair<F, S>& operator *() const { return *it; }
    /**
     * @param iterator с которым будем сравнивать
     * @return правда когда они указывают на один, ложь в обратном случае
     */
    bool operator ==(const iterator<F, S> &iterator) { return it == iterator.it; }
    /**
     * @param iterator с которым будем сравнивать
     * @return правда когда они указывают на разные адреса и ложь в обратном случае
     */
    bool operator !=(const iterator<F, S>  &iter) { return it != iter.it; }

};

template <typename F, typename S>
class map {
private:
    std::vector<std::pair<F, S>> arr;
public:
    map() = default;
    ~map() = default;
    /**
     * метод, возвращающий итератор на начало
     * @return итератор на начало
     */
    iterator<F, S> begin() { return iterator<F, S>(&(arr[0])); }
    /**
     * метод, возвращающий итератор на конец
     * @return итератор на конец
     */
    iterator<F, S> end() { return iterator<F, S>(&*arr.end()); }
    /**
     * метод поиска по мэпу
     * @param name первый параметр пары по которому осущ поиск
     * @return итератор указыв на найденную ячейку
     */
    iterator<F, S> find(const F index) {
        iterator<F, S> r = iterator<F, S>(&*arr.end());
        for (auto i = arr.begin(); i != arr.end(); ++i){
            if (i->first == index) { r = iterator<F, S>(&(*i)); }
        }
        return r;
    }
    /**
     * метод, вставляющий новую пару в массив
     * @param key первый параметр пары новой пары ячейки
     * @param obj второй параметр новой пары ячейки
     */
    void emplace(F key, S obj){
        arr.push_back(std::pair<F,S>(key, obj));
    }
    /**
     * метод удаляющий нужную ячейку
     * @param obj индекс пары которую нужно удалить
     */
    void erase(const F ind) {
        std::vector<std::pair<F, S>> tmp;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i].first != ind){
                tmp.push_back(arr[i]);
            }
            if (arr[i].first == ind){
                continue;
            }
        }
        arr = tmp;
    }
};
