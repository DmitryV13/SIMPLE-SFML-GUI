#pragma once
#include "InputField.h"

/** Элемент интерфейса, элемент формы - однострочное числовое поле ввода.

 */
class NumberField: public InputField {
private:
	float min;
	float max;
	bool isFloat;
	void inputLogic(int typed_char) override;
public:
    /**

        @param x координата.
        @param y координата.
        @param width_ ширина.
        @param height_ высота.
        @param input_label_ имя поля ввода.
        @param text_size_ размер шрифта.
        @param text_color_ цвет текста ввода.
        @param has_limit_ устанавливает/снмает ограничение по введенным символам.
        @param limit_ максимальное количество символов.
    */
	NumberField(float x, float y, float width_, float height_, const string& input_label_, int text_size_, Color text_color_, bool has_limit_, int limit_);

    /**

        @param x координата.
        @param y координата.
        @param width_ ширина.
        @param height_ высота.
        @param input_label_ имя поля ввода.
        @param text_size_ размер шрифта.
        @param has_limit_ устанавливает/снмает ограничение по введенным символам.
        @param limit_ максимальное количество символов.
    */
	NumberField(float x, float y, float width_, float height_, const string& input_label_, int text_size_, bool has_limit_, int limit_);
	~NumberField();

    /** Задает максимальное и минимальное допустимое значение для числового поля ввода. По умолчанию mun
     * усьановлен в минимальное значение типа float, max установлен в максимальное значение типа float и
     * isFloat установлен в true.

        @param min минимальное допустимое значение.
        @param max максимальное допустимое значение.
        @param isFloat_ задает тип данных значения числового поля ввода. Если установлен в false, то тип данных
        установится в int.
    */
	void setMinMaxType(float min, float max, bool isFloat_);

    /** Обновляет элемент.
    */
	void update() override;
};

