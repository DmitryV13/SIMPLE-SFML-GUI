#pragma once
#include "InterfaceItem.h"
#include "TextureManager.h"
#include "Warehouse.h"
#include "GeneralInfo.h"

using namespace sf;

/** Элемент интерфейса - шкала значения ресурса.

 */
class ScaleParameterBar : public InterfaceItem{
private:
	Sprite scale_bar;
	float* resource;
	float max_value;

	IntRect front_bar;
	IntRect middle_bar;
	IntRect back_bar;

	float offset;
	RectangleShape shape;
	Vector2f position;
public:
	ScaleParameterBar();

    /**

        @param x координата.
        @param y координата.
        @param width ширина.
        @param height высота.
        @param resource_ указатель на ресурс.
        @param max_value_ максимальное значение, которое может принимать ресурс.
        @param t_manager менеджер текстур.
        @param w_object обьект склада информации о сущностях.
        @param name название текстуры, сохраненной в менеджере текстур.
    */
	ScaleParameterBar(float x, float y, float width, float height, float* resource_, float max_value_, 
		TextureManager* t_manager, Warehouse* w_object, string name);
	~ScaleParameterBar();

	FloatRect getLocalBounds() override;
	FloatRect getGlobalBounds() override;

    /** Устанавливает новую позицию.

       @param new_position координаты новой позиции.
    */
	void setPosition(Vector2f new_position);

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

    /** Обновляет элемент.
    */
	void update() override;

    /** Отображает элемент.
    */
	void render() override;
};

