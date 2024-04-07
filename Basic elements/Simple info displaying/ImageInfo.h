#pragma once
#include "TextureManager.h"
#include "Warehouse.h"
#include "InterfaceItem.h"
#include "INTERFACE_ITEM_TYPE.h"

using namespace::sf;

/** Элемент интерфейса - подписанная текстура.
 */
class ImageInfo : public InterfaceItem {
protected:
	RectangleShape shape;//*2
	Text text;
	Sprite src_img;//*2
	Vector2f position;
public:
	ImageInfo();

    /**

        @param x координата.
        @param y координата.
        @param text_ текст подписи.
        @param text_size размер шрифта.
        @param t_manager менеджер текстур.
        @param index индекс строки содержащей данную текстуру.
        @param name название текстуры, сохраненной в менеджере текстур.
        @note текстура масштабируется таким образом, чтобы ее высота была в 2 раза больше высоты текста.
    */
	ImageInfo(float x, float y, string text_, int text_size, TextureManager* t_manager, int index, string name);

    /**

        @param x координата.
        @param y координата.
        @param text_ текст подписи.
        @param text_size размер шрифта.
        @param t_manager менеджер текстур.
        @param index индекс строки содержащей данную текстуру.
        @param name название текстуры, сохраненной в менеджере текстур.
        @note текстура масштабируется таким образом, чтобы ее высота была в 2 раза больше высоты текста.
    */
	ImageInfo(float x, float y, int text_, int text_size, TextureManager* t_manager, int index, string name);

	FloatRect getLocalBounds() override;
	FloatRect getGlobalBounds() override;

    /** Устанавливает новую позицию для элемента.

        @param new_position новая позиция.
    */
	virtual void setPosition(Vector2f new_position);

    /** Устанавливает новую координату x для элемента.

       @param x новая координата x.
    */
	void setPositionX(float x) override;

    /** Устанавливает новую координату y для элемента.

       @param y новая координата y.
    */
	void setPositionY(float y) override;

    /** Устанавливает новый текст для подписи.

       @param text_ новый текст для подписи.
    */
	void setText(float text_);

    /** Устанавливает цвет заливки заднего фона элемента. По умолчанию цвет фона прозрачный.

        @param color новый цвет фона.
    */
	void setBackgroundColor(Color color);

    /** Сдвигает элемент на заданное смещение.

       @param offset_x смещение по x.
       @param offset_y смещение по y.
    */
	void changePosition(float offset_x, float offset_y) override;

    /** Обновляет элемент.
    */
	void update() override;

    /** Отображает элемент.
    */
	void render() override;
};

