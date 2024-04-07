#pragma once
#include "InputField.h"

/** Элемент интерфейса, элемент формы - многострочное поле ввода.

 */
class TextareaField: public InputField{
private:
public:
    /**

        @param x координата.
        @param y координата.
        @param width_ ширина.
        @param height_ высота.
        @param input_label_ имя поля ввода.
        @param text_size_ размер шрифта.
        @param text_color_ цвет текста ввода (по умолчанию цвет текста черный).
        @param has_limit_ устанавливает/снмает ограничение по введенным символам.
        @param limit_ максимальное количество символов.
    */
	TextareaField(float x, float y, float width_, float height_, const string& input_label_, int text_size_, Color text_color_, bool has_limit_, int limit_);

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
	TextareaField(float x, float y, float width_, float height_, const string& input_label_, int text_size_, bool has_limit_, int limit_);
	~TextareaField();
};

