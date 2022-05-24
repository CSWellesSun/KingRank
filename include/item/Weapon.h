#ifndef WEAPON_H_
#define WEAPON_H_

#include "Item.h"
#include "common/Config.h"

class Weapon : public Item {
   public:
    Weapon() {}
    Weapon(string n, string d, int w, int attack, int abrasionLoss, int abrasion = maxAbrasion)
        : Item(n, d, w, WEAPON_ID), attack(attack), abrasion(abrasion), abrasionLoss(abrasionLoss) {}

    int GetAttack() const { return attack; }
    int GetAbrasion() const { return abrasion; }
    int GetAbrasionLoss() const { return abrasionLoss; }

    void SetAttack(int attack_) { attack = attack_; }
    void SetAbrasion(int abrasion_) { abrasion = abrasion_; }
    void SetAbrasionLoss(int abrasionLoss_) { abrasionLoss = abrasionLoss_; }

    bool Abrase();

    template <typename Writer>
    void Serialize(Writer& writer) const {
        writer.StartObject();

        Item::Serialize(writer);

        writer.String("attack");
        writer.Int(attack);
        writer.String("abrasion");
        writer.Int(abrasion);
        writer.String("abrasionLoss");
        writer.Int(abrasionLoss);

        writer.EndObject();
    }

   private:
    int attack;        // 攻击力
    int abrasion;      // 当前磨损量
    int abrasionLoss;  // 每使用一次的磨损量
};

#endif  // WEAPON_H_