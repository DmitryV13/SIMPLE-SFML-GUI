#pragma once
#include "InterfaceItem.h"
#include "ITEM_OVERFLOW.h"

/** Элемент интерфейса - текст.

 */
class Textarea : public InterfaceItem{
protected:
	Text* text;
	string* text_str;
	char cursor;

	RectangleShape background;

	int text_size;
	Color text_color;

	float offset_y;
	short overflow;
	bool multiline;
	bool visibility;

	float width;
	float height;
	Vector2f position;
public:
    /**

        @param x координата.
        @param y координата.
        @param width_ ширина.
        @param height_ высота.
        @param text_size_ размер шрифта.
        @param text_color_ цвет текста (по умолчанию цвет текста черный).
        @param background_color_ цвет фона текста (по умолчанию белый).
        @param border_color_ цвет границы фона текста (по умолчанию темно-синий).
        @param overflow_ устанавливает тип выхода содержимого за пределы текстового элемента (ITEM_OVERFLOW, по
        умолчанию HIDDEN).
        @param multiline_ устанавливает многострочность текстового элемента.
    */
	Textarea(float x, float y, float width_, float height_,  int text_size_, Color text_color_, 
		Color background_color_, Color border_color, short overflow_, bool multiline_);

    /**

        @param x координата.
        @param y координата.
        @param width_ ширина.
        @param height_ высота.
        @param text_size_ размер шрифта.
        @param multiline_ устанавливает многострочность текстового элемента.
    */
	Textarea(float x, float y, float width_, float height_, int text_size_, bool multiline_);
	~Textarea();

	FloatRect getLocalBounds() override;
	FloatRect getGlobalBounds() override;

    /** Возвращает указатель на строку текстового элемента.
    */
	std::string* getString();

    /** Возвращает последний символ текстового элемента. Если текстовый элемент пустой, возвратится ' '.
    */
	char getLastCharacter();

    /** Возвращает булевое значение, означающее видимость содержимого текстового элемента.
    */
	bool getVisibility();

    /** Возвращает булевое значение, означающее существование курсора текстового элемента.
    */
	bool hasCursor();

    /** Возвращает булевое значение, означающее переполнение контента текстового элемента.
    */
	bool contentOverflows();

    /** Устанавливает видимость содержимого текстового элемента.

        @param visibility_ новая видимость.
    */
	void setVisibility(bool visibility_);

    /** Устанавливает тип переполнения контента текстового элемента (ITEM_OVERFLOW).

        @param overflow_ тип переполнения.
    */
	void setOverflow(short overflow_);

    /** Устанавливает цвет заднего фона текстового элемента.

        @param color новый цвет.
    */
	void setBackgroungColor(Color color);

    /** Устанавливает цвет заднего фона текстового элемента.

        @param color новый цвет.
    */
	void setOutlineColor(Color color);

    /** Устанавливает цвет текста.

        @param color новый цвет.
    */
	void setTextColor(Color color);

    /** Устанавливает значение текста.

        @param new_str новый текст.
    */
	void setString(std::string new_str);

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

    /** Добавляет символ к тексту.

       @param ch символ.
    */
	void addCharacter(char ch);

    /** Устанавливает символ курсора.

       @param cursor_ новый символ курсора.
    */
	void addCursor(char cursor_);

    /** Удаляет символ в тексте по заданному индексу.

       @param cursor_ новый символ курсора.
    */
	void removeCharacter(int index);

    /** Удаляет последний символ в тексте.
    */
	void removeLastCharacter();

    /** Удаляет курсор.
    */
	void removeCursor();

    /** Системный метод.
    */
	vector<string> splitString(const string& str, char delimiter);

    /** Системный метод.
    */
	void scroll(float delta);

    /** Системный метод.
    */
	void normalization();


    /** Обновляет элемент.
    */
	void update() override;

    /** Отображает элемент.
    */
	void render() override;
};

