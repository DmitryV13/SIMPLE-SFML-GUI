#pragma once

using namespace::sf;

using CallbackFunctions = vector <std::function<void(float, float)>>;

using CallbackContainer = unordered_map<
	short*, CallbackFunctions>;

using Callbacks = unordered_map<
	short, CallbackContainer>;

using Parameters = unordered_map<
	short*, std::pair<float, float>>;

/**
* Класс манипулятор статическими откликами.
*/
class CallbacksHandler{
private:
	Callbacks w_callbacks;
	Parameters c_parameters;
public:
	CallbacksHandler();

    /** Добавление отклика
     *
     * @tparam T тип данных принимаемого l_instance.
     * @param b_state указатель на состояние, которое будет отслеживаться.
     * @param a_state значение активного состояния.
     * @param param1 первый параметр типа float, который передастся в метод передаваемого обьекта.
     * @param param2 второй параметр типа float, который передастся в метод передаваемого обьекта.
     * @param l_func метод обьекта l_instance с сигнатурой void l_func(float, float).
     * @param l_instance обьект, от которого вызовется переданный метод.
     * @return возвращает булевой значение, был ли успешно добавлен отклик.
     */
	template<class T>
	bool addCallback(short* b_state, short a_state, float param1, float param2, void(T::* l_func)(float, float), T* l_instance);

    /** Проверка и обновление состояний, от которых зависит активация откликов.
    */
	void update();
};

template<class T>
inline bool CallbacksHandler::addCallback(short* c_state, short a_state, float param1, float param2, void(T::* l_func)(float, float), T* l_instance) {
	c_parameters.insert({ c_state, {param1, param2} });
	auto itr = w_callbacks.emplace(a_state, CallbackContainer()).first;
	auto temp = std::bind(l_func, l_instance, std::placeholders::_1, std::placeholders::_2);
	bool inserted = itr->second.emplace(c_state, CallbackFunctions()).second;
	itr->second.at(c_state).push_back(temp);
	return inserted;
}
