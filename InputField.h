#pragma once
#include "InterfaceItem.h"
#include "FormItem.h"
#include "Textarea.h"
#include "FORM_ITEM_STATE.h"
#include "FORM_ITEM_TYPE.h"
#include "INTERFACE_ITEM_TYPE.h"

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

using namespace::sf;

/** Элемент интерфейса, элемент формы - однострочное поле ввода.

 */
class InputField: public InterfaceItem, public FormItem {
protected:
	Text* label;
	Textarea* textarea;
	std::ostringstream input_stream;

	int text_size;
	Color text_color;

	bool chosen;
	bool unpressed;

	RectangleShape shape1;

	bool has_limit;
	bool overflow_x;
	int limit;

	float width;
	float height;
	Vector2f position;

    /** Системный метод.
    */
	virtual void inputLogic(int typed_char);

    /** Системный метод.
    */
	void deletLastChar();

    /** Системный конструктор.
    */
	InputField(float x, float y, float width_, float height_, const string& input_label_, 
		int text_size_, Color text_color_, bool has_limit_, int limit_, bool multiline);

    /** Системный конструктор.
    */
    InputField(float x, float y, float width_, float height_, const string& input_label_, int text_size_);

    /** Системный конструктор.
    */
    InputField(float x, float y, float width_, float height_, const string& input_label_, int text_size_,
               Color text_color_, bool has_limit_, int limit_);
public:
    InputField();

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
	InputField(float x, float y, float width_, float height_, const string& input_label_, int text_size_, 
		bool has_limit_, int limit_);
	~InputField();

	FloatRect getLocalBounds() override;
	FloatRect getGlobalBounds() override;

    /** Возвращает содержимое поля ввода.
    */
	string* getString();

    /** Задает видимость введенных символов(если видимость установлена в false, то вместо символов
        пользователь увидит звездочки).

        @param vis видимость.
    */
	void setVisibility(bool vis);

    /** Не используется.

      @param overflow
     */
	void setOverflow(short overflow);

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

    /** Меняет видимость данных поля ввода.

       @param param1 параметр заглушка (не используется).
       @param param1 параметр заглушка (не используется).
    */
	void changeVisibility(float param1, float param2);

    /** Системный метод.
    */
	bool itemScroll(float delta) override;

    /** Системный метод.
    */
	void formEInput(Event event) override;

    /** Обновляет элемент.
    */
	void update() override;

    /** Отображает элемент.
    */
	void render() override;
};



