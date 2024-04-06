#pragma once
#include "FormItem.h"
#include "Group.h"
#include "FORM_ITEM_STATE.h"
#include "FORM_ITEM_TYPE.h"
#include "INTERFACE_ITEM_TYPE.h"

using namespace::sf;

/** Элемент интерфейса, элемент формы - checkbox группа. В данной версии содержание одной checkbox группы
    в другой checkbox группе допустимо, но неработоспособн, так как нет каскадной обработки события.

 */
class CheckboxItem: public Group, public FormItem{
private:
	RectangleShape shape;
	bool chosen;
	bool unpressed;
	string* value;
	string active_value;
	string idle_value;
public:
    /**

        @param x координата.
        @param y координата.
        @param width_ ширина.
        @param height_ высота.
        @note неактивированное значение checkbox по умолчанию "_false_", а активированное - "_true_".
    */
	CheckboxItem(float x, float y, float width_, float height_);
	~CheckboxItem();

    /** Возвращает текущее значение checkbox.
    */
	string* getValue();

    /** Устанавливает новое активированное значение checkbox.

        @param val новое акивированное значение.
    */
	void setValue(string val);

    /** Обновляет элемент.
    */
	void update() override;

    /** Отображает элемент.
    */
	void render() override;
};

