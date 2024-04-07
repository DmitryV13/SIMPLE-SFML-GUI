#pragma once
#include "InterfaceItem.h"
#include "FormItem.h"
#include "FORM_ITEM_STATE.h"
#include "FORM_ITEM_TYPE.h"

/** Элемент интерфейса, элемент формы - slider.

 */
class SliderControl: public InterfaceItem, public FormItem{
private:
	Text* label;
	string* s_value;
	float* f_value;
	bool isStatic;
	
	RectangleShape shape1;
	RectangleShape scale;
	CircleShape slider;

	float slider_offset_x;
	float mouse_pressed_pos_x;
	bool chosen;

	float min;
	float max;

	float width;
	float height;
	Vector2f position;

	void changeValue();
public:
    /**

        @param x координата.
        @param y координата.
        @param width_ ширина.
        @param height_ высота.
        @param input_label_ slider имя.
    */
	SliderControl(float x, float y, float width_, float height_, const string& input_label_);
	~SliderControl();

	FloatRect getLocalBounds() override;
	FloatRect getGlobalBounds() override;

    /** Установка минимального и максимального значения слайдера.

        @param min_ минимальное значение.
        @param max_ максимальное значение.
        @note вызов данного метода обязателен и должен быть выполнен до использования слайдера.
    */
	void setMinMaxType(float min_, float max_);

    /** Установка значения слайдера.

        @param value_ значение для динамического изменения ресурса.
        @param isStatic_ устанавливает, будет ли работать слайдер в статическом или динамическом режиме.
        @note динамический режим используется для изменения какого-то значения в программе в реальном времени,
        статический же режим предполагает, что установленное значение слайдера применится только в случае
        отправки формы.
    */
	void setValueType(float* value_, bool isStatic_);

    /** Устанавливает новую координату x для группы. Провоцирует изменение положения всех элементов группы.

       @param x новая координата x.
    */
	void setPositionX(float x) override;

    /** Устанавливает новую координату y для группы. Провоцирует изменение положения всех элементов группы.

       @param y новая координата y.
    */
	void setPositionY(float y) override;

    /** Сдвигает группу и ее элементы на заданное смещение.

       @param offset_x смещение по x.
       @param offset_y смещение по y.
    */
	void changePosition(float offset_x, float offset_y) override;

    /** Возвращает указатель на значение слайдера, если режим статический, иначе - nullptr.
    */
	string* getValue();

    /** Системный метод.
    */
	void scrollSlider(float mouse_pos_x);

    /** Отображает элемент.
    */
	void render() override;

    /** Обновляет элемент.
    */
	void update() override;
};

