#pragma once
#include "InterfaceItem.h"
#include "INTERFACE_ITEM_TYPE.h"
#include "BUTTON_STATE.h"
#include "TextureManager.h"

/** Элемент интерфейса - базовая кнопка.

 */
class Button : public InterfaceItem{
protected:
	short button_prstate;
	short button_cstate;
	RectangleShape shape;

	Text text;

	Vector2f position;
	Color btn_idle_color;
	Color btn_hover_color;
	Color btn_active_color;

	Color shp_idle_color;
	Color shp_hover_color;
	Color shp_active_color;

public:
	Button();

    /**

        @param x координата.
        @param y координата.
        @param text_size размер шрифта.
        @param text_ текст кнопки.
        @param menuColor цвет текста при наведении.
        @note кнопка будет представлять собой текст белого цвета с прозрачной границей(черной границей при
        наведении), размеры shape выставятся по размерам текста, цвет shape во всех состояниях будет
        прозрачным. Цвет текста при активации выставится в такой же цвет, как и при наведении.
    */
	Button(float x, float y, short text_size, string text_, Color menuColor);

    /**

        @param x координата.
        @param y координата.
        @param width ширина shape.
        @param height высота shape.
        @param text_size размер шрифта.
        @param text_ текст кнопки.
        @param menuColor цвет текста при наведении.
        @note кнопка будет представлять собой текст белого цвета с прозрачной границей(черной границей при
        наведении), текст помещается в центре shape, цвет shape во всех состояниях будет темно-синим.
        Цвет текста при активации выставится в такой же цвет, как и при наведении.
    */
	Button(float x, float y, float width, float height, short text_size, string text_
		, Color btn_hcolor);

    /**

        @param x координата.
        @param y координата.
        @param width ширина shape.
        @param height высота shape.
        @param text_size размер шрифта.
        @param text_ текст кнопки.
        @param outline значение, отвечающее за отображение границ обьекта shape.
        @note кнопка будет представлять собой текст с прозрачной границей(черной границей при наведении),
        текст помещается в центре shape. Все цвета выставляются с прозрачными значениями.
    */
	Button(float x, float y, float width, float height, short text_size, string text_
		, bool outline);
	~Button();

    /** Возвращает высоту прямоугольной области кнопки.
    */
	float getHeight();

    /** Возвращает ширину прямоугольной области кнопки.
    */
	float getWidth();

    /** Возвращает высоту текста кнопки.
    */

	float getTextHeight();

    /** Возвращает ширину текста кнопки.
    */
	float getTextWidth();

    /** Возвращает указательна текущее состояние кнопки кнопки.
    */
	short* getButtonState();

	FloatRect getLocalBounds() override;
	FloatRect getGlobalBounds() override;

    /** Устанавливает новую позицию для кнопки.

        @param new_position новая позиция.
    */
	virtual void setPosition(Vector2f new_position);

    /** Устанавливает новую координату x для кнопки.

       @param x новая координата x.
    */
	void setPositionX(float x) override;

    /** Устанавливает новую координату y для кнопки.

       @param y новая координата y.
    */
	void setPositionY(float y) override;

    /** Сдвигает кнопку на заданное смещение.

       @param offset_x смещение по x.
       @param offset_y смещение по y.
    */
	void changePosition(float offset_x, float offset_y) override;

    /** Задает все цвета для кнопки.

       @param btn_hcolor цвет активного текста и текста при наведении.
       @param btn_icolor цвет неактивного текста.
       @param shp_hcolor цвет активной прямоугольной области кнопки и прямоугольной области кнопки при наведении.
       @param shp_icolor цвет неактивной прямоугольной области кнопки.
    */
	void setColors(Color btn_hcolor, Color btn_icolor, Color shp_hcolor, Color shp_icolor);

    /** Задает единый цвет для прямоугольной области кнопки.

       @param shapeColor новый цвет.
    */
	void setBackgroundColor(Color shapeColor);

    /** Устанавливает текущее состояние кнопки в неактивное.
    */
	void resetActiveState() override;

    /** Возвращает логическое значение, отражающие - нажата кнопка или нет.
    */
	const bool isPressed() const;

    /** Системный метод.
    */
	virtual void updatePosition();

    /** Обновляет элемент.
    */
	void update() override;

    /** Отображает элемент.
    */
	void render() override;
};

