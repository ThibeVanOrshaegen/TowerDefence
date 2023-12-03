#include "Gold.h"
namespace Towerdefense
{
    template <typename T>
    Gold<T>::Gold(T maxGold) : currentGold(maxGold)
    {
    }

    template <typename T>
    T Gold<T>::getCurrentGold() const
    {
        return this->currentGold;
    }

    template <typename T>
    void Gold<T>::setCurrentGold(T Gold)
    {
        this->currentGold = Gold; //if this-> is weg dan geld werkt niet geen current en kan geen geld toevoegen
    }

    template <typename T>
    inline T Gold<T>::add(T a, T b)
    {
        return a + b;
    }

    template <typename T>
    inline T Gold<T>::subtract(T a, T b)
    {
        return a - b;
    }

    template <typename T>
    void Gold<T>::addMoney(T amount)
    {
        this->currentGold = add(currentGold, amount);
    }
    template <typename T>
    void Gold<T>::subtractMoney(T amount)
    {
        this->currentGold = subtract(currentGold, amount);
    }
    template class Gold<int>;
    template class Gold<double>;
    //template class Gold<char>;

}
