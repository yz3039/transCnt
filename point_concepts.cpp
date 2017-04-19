#include <chrono>

// a Point is a concept that holds a time (built-in duration type). 

template<typename T>
concept bool Point = requires(T p) {
        { p.get_time() } -> duration;
};


// There will be 6 concepts refined from the Point concept:

template<typename T>
concept bool PlaneWallPoint = Point<T> && requires(T p) {
        { p.get_rect_pos() } -> Position;
};

template<typename T>
concept bool InfCylPoint = Point<T> && requires(T p) {
        { p.get_cyl_pos() } -> Position;
};

template<typename T>
concept bool SpherePoint = Point<T> && requires(T p) {
        { p.get_sphere_pos() } -> Position;
};

template<typename T>
concept bool InfRectBarPoint = PlaneWallPoint<T> && requires(T p) {
        { p.get_rect_pos2() } -> Position;
};

template<typename T>
concept bool RectBarPoint = InfRectBarPoint<T> && requires(T p) {
        { p.get_rect_pos3() } -> Position;
};

template<typename T>
concept bool ShortCylPoint = InfCylPoint<T> && requires(T p) {
        { p.get_rect_pos() } -> Position;
};