#pragma once

using namespace::sf;

using DCallbackFunctions = vector <std::function<void(string*, string*)>>;

using DCallbackContainer = unordered_map<
	short*, DCallbackFunctions>;

using DCallbacks = unordered_map<
	short, DCallbackContainer>;

using DParameters = unordered_map<
	short*, std::pair<string*, string*>>;

/**
 * Класс манипулятор динамическими откликами
 */
class DCallbacksHandler {
private:
	DCallbacks w_callbacks;
	DParameters c_parameters;
public:
	DCallbacksHandler();

    /** Добавление отклика
     *
     * @tparam T тип данных принимаемого l_instance.
     * @param b_state указатель на состояние, которое будет отслеживаться.
     * @param a_state значение активного состояния.
     * @param param1 первый параметр типа string*, который передастся в метод передаваемого обьекта.
     * @param param2 второй параметр типа string*, который передастся в метод передаваемого обьекта.
     * @param l_func метод обьекта l_instance с сигнатурой void l_func(string*, string*).
     * @param l_instance обьект, от которого вызовется переданный метод.
     * @return возвращает булевой значение, был ли успешно добавлен отклик.
     */
	template<class T>
	bool addCallback(short* b_state, short a_state, string* param1, string* param2, void(T::* l_func)(string*, string*), T* l_instance);

    /** Проверка и обновление состояний, от которых зависит активация откликов.
     */
	void update();
};

template<class T>
inline bool DCallbacksHandler::addCallback(short* c_state, short a_state, string* param1, string* param2, void(T::* l_func)(string*, string*), T* l_instance) {
	c_parameters.insert({ c_state, {param1, param2} });
	auto itr = w_callbacks.emplace(a_state, DCallbackContainer()).first;
	auto temp = std::bind(l_func, l_instance, std::placeholders::_1, std::placeholders::_2);
	bool inserted = itr->second.emplace(c_state, DCallbackFunctions()).second;
	itr->second.at(c_state).push_back(temp);
	return inserted;
}

