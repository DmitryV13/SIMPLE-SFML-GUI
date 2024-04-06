#pragma once
#include "Group.h"
#include "FormItem.h"
#include "FORM_ITEM_STATE.h"
#include "CheckboxItem.h"

using namespace::sf;
using std::function;

using saction_type = function<void(std::vector<float>)>*;
using daction_type = function<void(std::vector<string>)>*;


/**
 * Класс для группировки элементов со смыслом сущности формы. Предназначен для хранения элементов формы
 * (на данный момент) на первом уровне вложенности, и обработки значений всех этих элементов при активаци
 * формы. На уровнях вложенности больше 1 хранить элементы форм можно, но их обработка не будет осуществляться.
 * По умолчанию форма является одноразовой - отправка произойдет только 1 раз, при первом срабатывании события
 * тригера.
 */
class Form : public Group{
private:
	std::vector<float> s_callback_params;
	std::vector<string> d_callback_params;
	saction_type s_action;
	daction_type d_action;
	bool activated;
	bool action_done;
	bool static_parameters;
public:
    /**

        @param x координата.
        @param y координата.
        @param width_ ширина.
        @param height_ высота.
    */
	Form(float x, float y, float width_, float height_);
	~Form();

    /** Возвращает элемент формы по заданным индексам.

        @param i индекс строки.
        @param j индекс столбца.
    */
	InterfaceItem* getElement(int i, int j);

    /** Устанавливает, будут ли принимаемые параметры статическими или нет.

        @param type логическое значение статических параметров.
        @note возможно в дальнейшем данный метод будет удален.
    */
	void setStaticParametersType(bool type);

    /** Делает допустимым повторную отправку формы. Может использоваться неограниченное количество раз.
        Если используется для формы, которая еще не была отправлена - ничего не произойдет.
    */
	void resetFormUsage();

    /** Добавляет событие отклика для статических параметров.

        @param params_amount количество параметров, которые будет содержать вектор для функции отклика.
        @param l_func функция отклика, имеет сигнатуру void l_func(vector<float>).
        @param l_instance обьект, от которого будет вызываться функция отклика.
    */
	template<class T>
	void addSFormAction(int params_amount, void(T::* l_func)(vector<float>), T* l_instance);

    /** Добавляет событие отклика для динамических параметров.

        @param params_amount количество параметров, которые будет содержать вектор для функции отклика.
        @param l_func функция отклика, имеет сигнатуру void l_func(vector<float>).
        @param l_instance обьект, от которого будет вызываться функция отклика.
    */
	template<class T>
	void addDFormAction(int params_amount, void(T::* l_func)(vector<string>), T* l_instance);

    /** Добавляет в вектор динамических параметров значение параметра по индексу.

        @param index индекс параметра в векторе.
        @param param значение параметра.
    */
	void addDCallbackParam(string* index, string* param);

    /** Добавляет в вектор статических параметров значение параметра по индексу.

        @param index индекс параметра в векторе.
        @param param значение параметра.
    */
	void addSCallbackParam(float index, float param);

    /** Активирует форму.

        @param param1 параметр заглушка (не используется).
        @param param2 параметр заглушка (не используется).
    */
	void activateForm(float param1, float param2);

    /** Обновляет форму и все элементы, которые ей принадлежат.
    */
	void update() override;
};

template<class T>
inline void Form::addSFormAction(int params_amount, void(T::* l_func)(vector<float>), T* l_instance) {
	s_callback_params.resize(params_amount);
	*s_action = std::bind(l_func, l_instance, std::placeholders::_1);
}

template<class T>
inline void Form::addDFormAction(int params_amount, void(T::* l_func)(vector<string>), T* l_instance) {
	d_callback_params.resize(params_amount);
	*d_action = std::bind(l_func, l_instance, std::placeholders::_1);
}
