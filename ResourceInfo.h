#pragma once
#include "ImageInfo.h"

using namespace::sf;

/** Элемент интерфейса - информационный ресурс. Создан для того, чтобы в реальном времени отображать
    количество заданного ресурса.
*/
class ResourceInfo : public ImageInfo{
private:
	int* resource;
	bool image;
	string max;
	string prev;
public:
	ResourceInfo();

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
	ResourceInfo(float x, float y, int text_size, bool image_);

    /**

        @param x координата.
        @param y координата.
        @param text_size размер шрифта.
        @param t_manager менеджер текстур.
        @param w_object обьект склада информации о сущностях.
        @param name название текстуры, сохраненной в менеджере текстур.
        @param image логическое значение присутствия картинки (для правильного отображения всегда выставлять в true).
        @note текстура масштабируется таким образом, чтобы ее высота была в 2 раза больше высоты текста.
    */
	ResourceInfo(float x, float y, int text_size, TextureManager* t_manager, Warehouse* w_object, string name, bool image_);

    /**

        @param x координата.
        @param y координата.
        @param resource_ указатель на ресурс.
        @param max_v максимальное значение ресурса. Если максимальное значение ресурса равно 0, значит ресурс
        неисчерпаем и следовательно после количества ресурса будет пустая строка, иначе после количества ресурса
        поставится слэш и добавится максимальное количество.
        @param text_size размер шрифта.
        @param t_manager менеджер текстур.
        @param index индекс строки содержащей данную текстуру.
        @param name название текстуры, сохраненной в менеджере текстур.
        @param self_align_ логическое значение присутствия картинки (для правильного отображения всегда выставлять в true).
        @note текстура масштабируется таким образом, чтобы ее высота была в 2 раза больше высоты текста.
    */
	ResourceInfo(float x, float y, int* resource_, int max_v, int text_size, TextureManager* t_manager, int index, string name, bool self_align_);
	~ResourceInfo();

    /** Добавляет всю необходимую информацию о ресурсе.

        @param t_manager менеджер текстур.
        @param w_object обьект склада информации о сущностях.
        @param name название текстуры, сохраненной в менеджере текстур.
        @param x логическое значение, задает будет ли отображаться X перед ресурсом.
        @note текстура масштабируется таким образом, чтобы ее высота была в 2 раза больше высоты текста.
    */
	void addInfo(TextureManager* t_manager, Warehouse* w_object, string name, bool x);

    /** Добавляет всю необходимую информацию о ресурсе.

        @param t_manager менеджер текстур.
        @param w_item конкретная сущность обьекта склада информации о сущностях.
        @param x логическое значение, задает будет ли отображаться X перед ресурсом.
        @note текстура масштабируется таким образом, чтобы ее высота была в 2 раза больше высоты текста.
    */
	void addInfo(TextureManager* t_manager, WarehouseItem* w_item, bool x);

    /** Обновляет элемент.
    */
	void update() override;
};

