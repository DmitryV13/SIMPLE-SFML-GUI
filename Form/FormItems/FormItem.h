#pragma once
#include "InterfaceItem.h"

using namespace::sf;

/** Базовый класс, от которго наследуются все элементы формы.
 *
 */
class FormItem{
protected:
	short fi_state;
	short fi_type;
public:
    /** Возвращает тип элемента формы.
    */
	short& getFIType();

    /** Возвращает состояние элемента формы.
    */
	short& getFIState();

    /** Возвращает указатель на состояние элемента формы.
    */
	short* getFIPState();

    /** Устанавливает состояние элемента формы.

        @param state новое состояние.
    */
	void setFIState(short state);

    /** Системный метод.
    */
	virtual void formEInput(Event event);
};

