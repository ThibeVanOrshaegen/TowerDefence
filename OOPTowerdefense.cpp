#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <cmath>
#include <random>
#include <iostream>

#define M_PI 3.14159265358979323846

class TextureManager
{
public:
    //Title

    sf::Texture texturetitle;
    sf::Sprite spritetitle;

    //OpeningScreen

    sf::Texture textureAchtergrond;
    sf::Sprite spriteAchtergrond;

    //Playbutton

    sf::Texture textureplay;
    sf::Sprite spriteplay;

    //Playbutton

    sf::Texture textureoption;
    sf::Sprite spriteoption;

    //Towerdefensetext

    sf::Texture texturetowerdefensetext;
    sf::Sprite spritetowerdefensetext;

    
    //Pad

    sf::Texture* texture;
    sf::Sprite* sprite;

    //Kasteel

    sf::Texture texturecastle;
    sf::Sprite spritecastle;
    

    //Perkament 

    sf::Texture texturepaper;
    sf::Sprite spritepaper;

    sf::Texture texturevbCannon;
    sf::Sprite spritevbCannon;

    sf::Texture texturevbCannon2;
    sf::Sprite spritevbCannon2;

    sf::Texture texturevbCannon3;
    sf::Sprite spritevbCannon3;

    sf::Texture texturevbMG;
    sf::Sprite spritevbMG;

    sf::Texture texturevbMG2;
    sf::Sprite spritevbMG2;

    sf::Texture texturevbMG3;
    sf::Sprite spritevbMG3;

    sf::Texture texturevbMissile_Launcher;
    sf::Sprite spritevbMissile_Launcher;

    sf::Texture texturevbMissile_Launcher2;
    sf::Sprite spritevbMissile_Launcher2;

    sf::Texture texturevbMissile_Launcher3;
    sf::Sprite spritevbMissile_Launcher3;

    sf::Texture texturegamemenutext;
    sf::Sprite spritegamemenutext;

    //Moder plaatse, Plaats om op te bouwen(als er voldoende munten zijn)

    sf::Texture texturemudeen;
    sf::Sprite spritemudeen;

    sf::Texture texturemudtwee;
    sf::Sprite spritemudtwee;

    sf::Texture texturemuddrie;
    sf::Sprite spritemuddrie;

    sf::Texture texturemudvier;
    sf::Sprite spritemudvier;

    sf::Texture texturemudvijf;
    sf::Sprite spritemudvijf;

    sf::Texture texturemudzes;
    sf::Sprite spritemudzes;

    //Canon

    sf::Texture textureshootereen;
    sf::Sprite spriteshootereen;

    sf::Texture textureshootertwee;
    sf::Sprite spriteshootertwee;

    sf::Texture textureshooterdrie;
    sf::Sprite spriteshooterdrie;

    sf::Texture textureshootervier;
    sf::Sprite spriteshootervier;

    //Enemy

    sf::Texture texturerobottwee;
    sf::Sprite spriterobottwee;

    sf::Texture texturerobotdrie;
    sf::Sprite spriterobotdrie;

    //Geld

    sf::Texture texturegold;
    sf::Sprite spritegold;

    //Laser
    sf::Texture texturelaser;
    sf::Sprite spritelaser;

    //MG
    sf::Texture textureMG;
    sf::Sprite spriteMG;



    TextureManager()
    {
        texture = new sf::Texture();
        sprite = new sf::Sprite();

        //OpeningScreen

        textureAchtergrond.loadFromFile("./cooltitlescreen.jpg");
        spriteAchtergrond.setTexture(textureAchtergrond);
        sf::Vector2f AchtergrondPosition(0, 0);
        spriteAchtergrond.setPosition(AchtergrondPosition);
        spriteAchtergrond.setScale(1.0f, 1.0f);

        //Title

        texturetitle.loadFromFile("./paperrolverticaal.png");
        spritetitle.setTexture(texturetitle);
        sf::Vector2f TitlePosition(10, 200);
        spritetitle.setPosition(TitlePosition);
        spritetitle.setScale(0.7f, 0.44f);

        //Playbutton

        textureplay.loadFromFile("./newplay.png");
        spriteplay.setTexture(textureplay);
        sf::Vector2f PlaybuttonPosition(150, 290);
        spriteplay.setPosition(PlaybuttonPosition);
        spriteplay.setScale(0.3f, 0.3f);

        //Optionbutton

        textureoption.loadFromFile("./Newoptions.png");
        spriteoption.setTexture(textureoption);
        sf::Vector2f optionPosition(140, 350);
        spriteoption.setPosition(optionPosition);
        spriteoption.setScale(0.25f, 0.25f);

        //Towerdefense Text

        texturetowerdefensetext.loadFromFile("./towertextonder.png");
        spritetowerdefensetext.setTexture(texturetowerdefensetext);
        sf::Vector2f towerdefensetextPosition(0, 20);
        spritetowerdefensetext.setPosition(towerdefensetextPosition);
        spritetowerdefensetext.setScale(0.7f, 0.5f);

        
        //Pad

        texture->loadFromFile("./plattegrond.png");
        sprite->setTexture(*texture);


        //Kasteel

        texturecastle.loadFromFile("./Castletwee.png");
        spritecastle.setTexture(texturecastle);
        sf::Vector2f castlePosition(1050, 80);
        spritecastle.setPosition(castlePosition);
        spritecastle.setRotation(30);
        spritecastle.setScale(1.8f, 1.8f);

        //Paper
        texturepaper.loadFromFile("./perkament.png");
        spritepaper.setTexture(texturepaper);
        sf::Vector2f paperPosition(100,100);
        spritepaper.setPosition(paperPosition);
        spritepaper.setScale(2.0f, 2.0f);

        //Upgrades
        texturevbCannon.loadFromFile("./Cannon.png");
        spritevbCannon.setTexture(texturevbCannon);
        sf::Vector2f vbCannonPosition(210, 240);
        spritevbCannon.setPosition(vbCannonPosition);
        spritevbCannon.setRotation(270);
        spritevbCannon.setScale(0.3f, 0.3f);

        texturevbCannon2.loadFromFile("./Cannon2.png");
        spritevbCannon2.setTexture(texturevbCannon2);
        sf::Vector2f vbCannon2Position(310, 250);
        spritevbCannon2.setPosition(vbCannon2Position);
        spritevbCannon2.setRotation(270);
        spritevbCannon2.setScale(0.3f, 0.3f);

        texturevbCannon3.loadFromFile("./Cannon3.png");
        spritevbCannon3.setTexture(texturevbCannon3);
        sf::Vector2f vbCannon3Position(420, 250);
        spritevbCannon3.setPosition(vbCannon3Position);
        spritevbCannon3.setRotation(270);
        spritevbCannon3.setScale(0.3f, 0.3f);

        texturevbMG.loadFromFile("./MG.png");
        spritevbMG.setTexture(texturevbMG);
        sf::Vector2f vbMGPosition(210, 340);
        spritevbMG.setPosition(vbMGPosition);
        spritevbMG.setRotation(270);
        spritevbMG.setScale(0.3f, 0.3f);

        texturevbMG2.loadFromFile("./MG2.png");
        spritevbMG2.setTexture(texturevbMG2);
        sf::Vector2f vbMG2Position(310, 340);
        spritevbMG2.setPosition(vbMG2Position);
        spritevbMG2.setRotation(270);
        spritevbMG2.setScale(0.3f, 0.3f);

        texturevbMG3.loadFromFile("./MG3.png");
        spritevbMG3.setTexture(texturevbMG3);
        sf::Vector2f vbMG3Position(410, 340);
        spritevbMG3.setPosition(vbMG3Position);
        spritevbMG3.setRotation(270);
        spritevbMG3.setScale(0.3f, 0.3f);

        texturevbMissile_Launcher.loadFromFile("./Missile_Launcher.png");
        spritevbMissile_Launcher.setTexture(texturevbMissile_Launcher);
        sf::Vector2f vbMissile_LauncherPosition(210, 440);
        spritevbMissile_Launcher.setPosition(vbMissile_LauncherPosition);
        spritevbMissile_Launcher.setRotation(270);
        spritevbMissile_Launcher.setScale(0.3f, 0.3f);

        texturevbMissile_Launcher2.loadFromFile("./Missile_Launcher2.png");
        spritevbMissile_Launcher2.setTexture(texturevbMissile_Launcher2);
        sf::Vector2f vbMissile_Launcher2Position(335, 450);
        spritevbMissile_Launcher2.setPosition(vbMissile_Launcher2Position);
        spritevbMissile_Launcher2.setRotation(270);
        spritevbMissile_Launcher2.setScale(0.3f, 0.3f);

        texturevbMissile_Launcher3.loadFromFile("./Missile_Launcher3.png");
        spritevbMissile_Launcher3.setTexture(texturevbMissile_Launcher3);
        sf::Vector2f vbMissile_Launcher3Position(440, 455);
        spritevbMissile_Launcher3.setPosition(vbMissile_Launcher3Position);
        spritevbMissile_Launcher3.setRotation(270);
        spritevbMissile_Launcher3.setScale(0.3f, 0.3f);

        // GamemenuText



        //Moder plaatse, Plaats om op te bouwen(als er voldoende munten zijn)

        texturemudeen.loadFromFile("./mudtwee.png");
        spritemudeen.setTexture(texturemudeen); //anders laat die moddervlek niet zien
        sf::Vector2f mudeenPosition(225, 230);
        spritemudeen.setPosition(mudeenPosition);
        spritemudeen.setScale(0.3f, 0.3f);

        texturemudtwee.loadFromFile("./mudtwee.png");
        spritemudtwee.setTexture(texturemudtwee); //anders laat die moddervlek niet zien
        sf::Vector2f mudtweePosition(225, 400);
        spritemudtwee.setPosition(mudtweePosition);
        spritemudtwee.setScale(0.3f, 0.3f);

        texturemuddrie.loadFromFile("./mudtwee.png");
        spritemuddrie.setTexture(texturemuddrie); //anders laat die moddervlek niet zien
        sf::Vector2f muddriePosition(0, 250);
        spritemuddrie.setPosition(muddriePosition);
        spritemuddrie.setScale(0.25f, 0.25f);

        texturemudzes.loadFromFile("./mudtwee.png");
        spritemudzes.setTexture(texturemudzes); //anders laat die moddervlek niet zien
        sf::Vector2f mudzesPosition(0, 470);
        spritemudzes.setPosition(mudzesPosition);
        spritemudzes.setScale(0.25f, 0.25f);

        texturemudvier.loadFromFile("./mudtwee.png");
        spritemudvier.setTexture(texturemudvier); //anders laat die moddervlek niet zien
        sf::Vector2f mudvierPosition(505, 320);
        spritemudvier.setPosition(mudvierPosition);
        spritemudvier.setScale(0.3f, 0.3f);

        texturemudvijf.loadFromFile("./mudtwee.png");
        spritemudvijf.setTexture(texturemudvijf); //anders laat die moddervlek niet zien
        sf::Vector2f mudvijfPosition(800, 400);
        spritemudvijf.setPosition(mudvijfPosition);
        spritemudvijf.setScale(0.3f, 0.3f);

        //Weapons

        textureshootereen.loadFromFile("./canonzo.png"); // x = +70, y = +40
        spriteshootereen.setTexture(textureshootereen);
        sf::Vector2f shootereenPosition(320, 300);
        spriteshootereen.setPosition(shootereenPosition);
        spriteshootereen.setRotation(180);
        spriteshootereen.setScale(0.1f, 0.1f);

        textureshootertwee.loadFromFile("./canonzo.png");
        spriteshootertwee.setTexture(textureshootertwee);
        sf::Vector2f shootertweePosition(288, 440);
        spriteshootertwee.setPosition(shootertweePosition);
        spriteshootertwee.setScale(0.1f, 0.1f);

        textureshooterdrie.loadFromFile("./Missile_Launcher.png");
        spriteshooterdrie.setTexture(textureshooterdrie);
        sf::Vector2f shooterdriePosition(610, 400);
        spriteshooterdrie.setPosition(shooterdriePosition);
        spriteshooterdrie.setRotation(180);
        spriteshooterdrie.setScale(0.4f, 0.4f);

        textureshootervier.loadFromFile("./MG.png");
        spriteshootervier.setTexture(textureshootervier);
        sf::Vector2f shootervierPosition(100, 340);
        spriteshootervier.setPosition(shootervierPosition);
        spriteshootervier.setRotation(180);
        spriteshootervier.setScale(0.4f, 0.4f);

        //Weapon Upgrades

        //Enemy

        texturerobottwee.loadFromFile("./Robottwee.png");
        spriterobottwee.setTexture(texturerobottwee);
        spriterobottwee.setScale(0.3f, 0.3f);

        //Geld
        
        texturegold.loadFromFile("./munteindelijk.png"); //moet getal onderaan staan dat het aantal munten bijhoud met geld teken naast
        spritegold.setTexture(texturegold);
        spritegold.setScale(0.2f, 0.2f);

    }
    ~TextureManager()
    {
        
        delete texture;
        delete sprite;
    }
};

class HealthBar
{
public:
    sf::RectangleShape bar;
    sf::Vector2f position;
    int maxHealth = 100;
    int currentHealth = 0;

    HealthBar(sf::Vector2f enemyPosition, sf::Vector2f size, int maxHealth)
        : currentHealth(maxHealth)
    {
        bar.setPosition(enemyPosition.x, enemyPosition.y - 20);
        bar.setSize(size);
        bar.setFillColor(sf::Color::Red);
    }
    int getCurrentHealth() const {
        return currentHealth;
    }

    void setCurrentHealth(int health) {
        currentHealth = health;
    }
   
    void applyDamage()
    {
        float redHealthBarSizeIncrease = 0.1f;
        sf::Vector2f newSize = bar.getSize() - sf::Vector2f(50 * redHealthBarSizeIncrease, 0);
        bar.setSize(newSize);
        if (newSize.x > 0)
        {
            bar.setSize(newSize);
        }
        else
        {
            bar.setSize(sf::Vector2f(0, bar.getSize().y));
        }
    }
     void updatePosition(const sf::Vector2f& newPosition)
    {
        position = newPosition;
        bar.setPosition(position);
    }

};

class Beweging
{
private:
    float xVelocity;
    float yVelocity;
    float originalYVelocity;

public:
    Beweging(float xVel, float yVel) : xVelocity(xVel), yVelocity(yVel), originalYVelocity(yVel) {}

    void move(sf::Vector2f& position)
    {
        if (position.x < 170 && (position.y > 100 && position.y < 420))
        {
            position.x += xVelocity;
        }
        if ((position.x >= 170 && position.x < 200) && position.y > 172)
        {
            position.y -= yVelocity;
        }
        if (position.x < 412 && position.y < 172)
        {
            position.x += xVelocity;
        }
        if ((position.x >= 412 && position.x <= 700) && position.y < 172)
        {
            yVelocity *= -1;
        }
        if (position.y < 490 && position.x >= 412)
        {
            position.y -= yVelocity;
        }
        if (position.x < 734 && position.y >= 490)
        {
            position.x += xVelocity;
        }
        if (position.x >= 734 && position.y >= 340)
        {
            yVelocity = originalYVelocity;
            position.y -= yVelocity;
        }

        if (position.x >= 734 && position.y <= 340)
        {
            yVelocity = 0;

            if (position.x <= 1000)
            {
                position.x += xVelocity;
            }
        }
    }
};

class Enemy : public HealthBar
{
private:

    TextureManager textureManager;
    Beweging beweging;

public:
    sf::Sprite spriterobottwee;

    Enemy(sf::Vector2f initialPosition, sf::Vector2f size, int RandommaxHealth, float xVelocity, float yVelocity)
        : HealthBar(initialPosition, size, maxHealth), beweging(xVelocity, yVelocity)
    {
        textureManager.texturerobottwee.loadFromFile("./Robottwee.png");
        spriterobottwee.setTexture(textureManager.texturerobottwee);
        spriterobottwee.setPosition(initialPosition);
        spriterobottwee.setScale(0.3f, 0.3f);

    }

    void update()
    {
        sf::Vector2f positionRobottwee = spriterobottwee.getPosition();
        beweging.move(positionRobottwee);
        spriterobottwee.setPosition(positionRobottwee);

        updateHealthBar();

    }
    void updateHealthBar()
    {
        float healthPercentage = static_cast<float>(getCurrentHealth()) / static_cast<float>(maxHealth);
        sf::Vector2f newSize(healthPercentage * bar.getSize().x, bar.getSize().y);
        bar.setSize(newSize);
 
    }

};



//class Damage : 

class Gold
{
private:
    TextureManager textureManager;

public:
    
    int maxGold = 100;
    int currentGold = 10;

    Gold(sf::Vector2f GoldPosition, int maxGold)
        : currentGold(currentGold)
    {
        textureManager.texturegold.loadFromFile("./munteindelijk.png");
        textureManager.spritegold.setTexture(textureManager.texturelaser);
        textureManager.spritegold.setPosition(GoldPosition.x, GoldPosition.y);
    }

};

class Weapon
{
public:
    virtual void fire(sf::Vector2f shooterPosition) = 0;
    virtual void update() = 0;
};

class Canon : public Weapon
{
private:
    sf::Vector2f initialPosition;
    sf::Vector2f arrowPosition;

public:
    sf::CircleShape arrow;
    Canon(sf::Vector2f initialPosition) : arrow(), arrowPosition(initialPosition), initialPosition(initialPosition)
    {
        arrow.setFillColor(sf::Color::Black);
        arrow.setRadius(15.f); //Scale gedaan in plaats van Radius dan gaat het niks weer
        arrow.setPosition(initialPosition);
    }

    void fire(sf::Vector2f shooterPosition)override
    {

        float arrowSpeed = 5;
        arrowPosition.y += arrowSpeed;
        arrowPosition.x -= arrowSpeed;

        arrow.setPosition(arrowPosition);
        if (arrowPosition.y < 0 || arrowPosition.x <0)
        {
            arrowPosition.y = 240;
           arrowPosition.x = 240;
            

        }

    }
    void update() override
    {
        float arrowSpeed = 10;
        arrow.move(0, -arrowSpeed);

    }
};

class Laser : public Weapon
{
private:
    sf::Vector2f laserPosition;
    TextureManager textureManager;

public:
    sf::Sprite spritelaser;
    Laser(sf::Vector2f initialPosition) : spritelaser(), laserPosition(initialPosition)
    {
        textureManager.texturelaser.loadFromFile("./Missile.png");
        spritelaser.setTexture(textureManager.texturelaser);
        spritelaser.setPosition(initialPosition);
        spritelaser.setScale(0.4f, 0.4f);
        spritelaser.setRotation(180);
    }

    void fire(sf::Vector2f shootereenPosition)override
    {

        float laserSpeed = 7;
        laserPosition.y += laserSpeed;
        laserPosition.x += laserSpeed;

        spritelaser.setPosition(laserPosition);
        if (laserPosition.y > 500 || laserPosition.x > 700)
        {
            laserPosition.y = 410;
            laserPosition.x = 600;
        }

    }
    void update()override
    {
        float laserSpeed = 5;
        spritelaser.move(-laserSpeed, -laserSpeed);


    }
};

class MG : public Weapon
{
public:
private:
    sf::Vector2f MGPosition;
    TextureManager textureManager;

public:
    sf::Sprite spriteMG;
    MG(sf::Vector2f initialPosition) : spriteMG(), MGPosition(initialPosition)
    {
        textureManager.textureMG.loadFromFile("./Bullet_MG.png");
        spriteMG.setTexture(textureManager.textureMG);
        spriteMG.setPosition(initialPosition);
        spriteMG.setScale(0.4f, 0.4f);
    }

    void fire(sf::Vector2f shootervierPosition)override
    {

        float MGSpeed = 7;
        MGPosition.y += MGSpeed;
        MGPosition.x += MGSpeed;
        spriteMG.setPosition(MGPosition);
        if (MGPosition.y >  400|| MGPosition.x > 150)
        {
            MGPosition.y = 320;
            MGPosition.x = 65;
        }

    }
    void update()override
    {
        float MGSpeed = 5;
        spriteMG.move(0, -MGSpeed);


    }
};

class Game
{
private:

    HealthBar healthBar_een;
    HealthBar healthBar_twee;
    HealthBar healthBar_drie;
    HealthBar healthBar_vier;

    HealthBar redhealthBar_een;
    HealthBar redhealthBar_twee;
    HealthBar redhealthBar_drie;
    HealthBar redhealthBar_vier;

    Enemy snel;
    Enemy traag;
    Enemy snelxtraagy;
    Enemy traagxsnely;

    Canon canon;
    Laser laser;
    MG mg;

    TextureManager textureManager;

    bool spriteVisibleP = false;
    bool spriteVisibleC = false;

    bool spriteVisiblecanon = false;
    bool spriteVisiblelaser = false;
    bool spriteVisiblemg = false;

public:
    Game()

        :healthBar_een(sf::Vector2f(100, 400), sf::Vector2f(70, 10), 50),
        healthBar_twee(sf::Vector2f(800, 400), sf::Vector2f(70, 10), 70),
        healthBar_drie(sf::Vector2f(100, 400), sf::Vector2f(70, 10), 50),
        healthBar_vier(sf::Vector2f(800, 400), sf::Vector2f(70, 10), 70),

        redhealthBar_een(sf::Vector2f(100, 400), sf::Vector2f(70, 10), 50),
        redhealthBar_twee(sf::Vector2f(800, 400), sf::Vector2f(70, 10), 70),
        redhealthBar_drie(sf::Vector2f(100, 400), sf::Vector2f(70, 10), 50),
        redhealthBar_vier(sf::Vector2f(800, 400), sf::Vector2f(70, 10), 70),

        snel(sf::Vector2f(0, 410), sf::Vector2f(50, 50), 30, 9.0f, 9.0f), //de snelheden of maxhealt random maken
        traag(sf::Vector2f(0, 410), sf::Vector2f(50, 50), 70, 2.5f, 2.5f),
        snelxtraagy(sf::Vector2f(0, 410), sf::Vector2f(50, 50), 30, 5.0f, 2.5f),
        traagxsnely(sf::Vector2f(0, 410), sf::Vector2f(50, 50), 70, 2.5f, 5.0f),

        canon(sf::Vector2f(150,180)),
        laser(sf::Vector2f(610, 400)),
        mg(sf::Vector2f(65, 340))

    {
    }
 
    void updateShooterRotation()
    {
        sf::Vector2f shooterdriePosition = textureManager.spriteshooterdrie.getPosition();
        sf::Vector2f shootereenPosition = textureManager.spriteshootereen.getPosition();
        sf::Vector2f shootervierPosition = textureManager.spriteshootervier.getPosition();

        sf::Vector2f laserPosition = laser.spritelaser.getPosition();
        sf::Vector2f MGPosition = mg.spriteMG.getPosition();
        sf::Vector2f arrowPosition = canon.arrow.getPosition();

        sf::Vector2f robotPosition = traag.spriterobottwee.getPosition(); 

        float dxdrie = robotPosition.x - shooterdriePosition.x;
        float dydrie = robotPosition.y - shooterdriePosition.y;

        float dxeen = robotPosition.x - shootereenPosition.x;
        float dyeen = robotPosition.y - shootereenPosition.y;

        float dxvier = robotPosition.x - shootervierPosition.x;
        float dyvier = robotPosition.y - shootervierPosition.y;



        float distancedrie = std::sqrt(dxdrie * dxdrie + dydrie * dydrie);
        float distanceeen = std::sqrt(dxeen * dxeen + dyeen * dyeen);
        float distancevier = std::sqrt(dxvier * dxvier + dyvier * dyvier);

        if (distancedrie < 150.0f)
        {
            float angledrie = atan2(dydrie, dxdrie) * 180 / M_PI;
            textureManager.spriteshooterdrie.setRotation(angledrie+ 90);
            textureManager.spriteshooterdrie.setOrigin(textureManager.spriteshooterdrie.getLocalBounds().width / 2, textureManager.spriteshooterdrie.getLocalBounds().height / 2);

            laser.spritelaser.setRotation(angledrie + 90); //werkt
            laser.spritelaser.setOrigin(laser.spritelaser.getLocalBounds().width / 2, laser.spritelaser.getLocalBounds().height / 2); // Instelling van de oorsprong

            spriteVisiblelaser = true;

        }

        if (distanceeen < 300.0f)
        {
            float angleeen = atan2(dyeen, dxeen) * 180 / M_PI;
            textureManager.spriteshootereen.setRotation(angleeen +270);
            textureManager.spriteshootereen.setOrigin(textureManager.spriteshootereen.getLocalBounds().width / 2, textureManager.spriteshootereen.getLocalBounds().height / 2);

            canon.arrow.setRotation(angleeen +270);
            canon.arrow.setOrigin(canon.arrow.getLocalBounds().width / 2, canon.arrow.getLocalBounds().height / 2);

            spriteVisiblecanon = true;
        }

        if (distancevier  < 100.0f)
        {
            float anglevier = atan2(dyvier, dxvier) * 90 / M_PI;
            textureManager.spriteshootervier.setRotation(anglevier +90);
            textureManager.spriteshootervier.setOrigin(textureManager.spriteshootervier.getLocalBounds().width / 2, textureManager.spriteshootervier.getLocalBounds().height / 2);

            mg.spriteMG.setRotation(anglevier +90); //werkt
            mg.spriteMG.setOrigin(mg.spriteMG.getLocalBounds().width / 2, mg.spriteMG.getLocalBounds().height / 2);

            spriteVisiblemg = true;

        }
        else if (distancedrie > 150.0)
        {
            textureManager.spriteshooterdrie.setRotation(180);
            spriteVisiblelaser = false;
        }
        else if (distanceeen > 300.0f)
        {
            textureManager.spriteshootereen.setRotation(180);
            spriteVisiblecanon = false;
        }
        else if (distancevier > 50.0f)
        {
            textureManager.spriteshootervier.setRotation(180);
            spriteVisiblemg = false;
            
        }
        else
        {
            textureManager.spriteshooterdrie.setRotation(180);
            textureManager.spriteshootereen.setRotation(180);
            textureManager.spriteshootervier.setRotation(180);

        }

        sf::Vector2f fixedPositiondrie = textureManager.spriteshooterdrie.getPosition();
        textureManager.spriteshooterdrie.setPosition(fixedPositiondrie);

        sf::Vector2f fixedPositioneen = textureManager.spriteshootereen.getPosition();
        textureManager.spriteshootereen.setPosition(fixedPositioneen);

        sf::Vector2f fixedPositionvier = textureManager.spriteshootervier.getPosition();
        textureManager.spriteshootervier.setPosition(fixedPositionvier);
    }

    void useWeapon(Weapon& weapon, sf::Vector2f shooterPosition)
    {
        weapon.fire(shooterPosition);
    }

    void run(sf::RenderWindow& window)
    {
        window.setFramerateLimit(60);

        bool isRKeyPressed = false;
        bool isPKeyPressed = false;
        bool isCKeyPressed = false;

        redhealthBar_een.bar.setFillColor(sf::Color::Green);
        redhealthBar_twee.bar.setFillColor(sf::Color::Green);
        redhealthBar_drie.bar.setFillColor(sf::Color::Green);
        redhealthBar_vier.bar.setFillColor(sf::Color::Green);


        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    window.close();

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
                {
                    isPKeyPressed = true;
                    isRKeyPressed = false; 
                    isCKeyPressed = false;
                    spriteVisibleP = true;
                    spriteVisibleC = false;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
                {
                    isRKeyPressed = true;
                    isPKeyPressed = false; 
                    isCKeyPressed = false;
                    spriteVisibleP = false; 
                    spriteVisibleC = false;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
                {
                    isCKeyPressed = true;
                    isRKeyPressed = false;
                    isPKeyPressed = false;
                    spriteVisibleP = false; 
                    spriteVisibleC = true;
                }
                else
                {
                    isRKeyPressed = false;
                    isPKeyPressed = false;
                    isCKeyPressed = false;
                }
            }

            // Render
            window.clear();

            window.draw(textureManager.spriteAchtergrond);
            window.draw(textureManager.spritetowerdefensetext);
            window.draw(textureManager.spritetitle);
            window.draw(textureManager.spriteplay);
            window.draw(textureManager.spriteoption);

            if (spriteVisibleP)
            {

            window.draw(*(textureManager.sprite));
            window.draw(textureManager.spritecastle);


           /* window.draw(textureManager.spritepaper);
            window.draw(textureManager.spritevbCannon);
            window.draw(textureManager.spritevbCannon2);
            window.draw(textureManager.spritevbCannon3);

            window.draw(textureManager.spritevbMG);
            window.draw(textureManager.spritevbMG2);
            window.draw(textureManager.spritevbMG3);

            window.draw(textureManager.spritevbMissile_Launcher);
            window.draw(textureManager.spritevbMissile_Launcher2);
            window.draw(textureManager.spritevbMissile_Launcher3);*/

            //if (spriteVisibleC)
            //{
                window.draw(textureManager.spritemudeen);
                window.draw(textureManager.spritemudtwee);
                window.draw(textureManager.spritemuddrie);
                window.draw(textureManager.spritemudvier);
                window.draw(textureManager.spritemudvijf);


                window.draw(textureManager.spriteshootereen);
                window.draw(textureManager.spriteshootertwee);
                window.draw(textureManager.spriteshooterdrie);
                window.draw(textureManager.spriteshootervier);

                
                window.draw(snel.spriterobottwee);
                window.draw(traag.spriterobottwee);
                window.draw(snelxtraagy.spriterobottwee);
                window.draw(traagxsnely.spriterobottwee);

                window.draw(textureManager.spritemudeen);
                window.draw(textureManager.spritemudtwee);
                window.draw(textureManager.spritemuddrie);
                window.draw(textureManager.spritemudvier);
                window.draw(textureManager.spritemudvijf);
                window.draw(textureManager.spritemudzes);

                window.draw(textureManager.spriteshootereen);
                window.draw(textureManager.spriteshootertwee);
                window.draw(textureManager.spriteshooterdrie);
                window.draw(textureManager.spriteshootervier);

                window.draw(snel.spriterobottwee);
                window.draw(traag.spriterobottwee);
                window.draw(snelxtraagy.spriterobottwee);
                window.draw(traagxsnely.spriterobottwee);

                updateShooterRotation();


                snel.update();
                traag.update();
                snelxtraagy.update();
                traagxsnely.update();

                useWeapon(laser, textureManager.spriteshooterdrie.getPosition());

                if (spriteVisiblelaser)
                window.draw(laser.spritelaser);

                useWeapon(mg, textureManager.spriteshootervier.getPosition());

                if(spriteVisiblemg)
                window.draw(mg.spriteMG);

                useWeapon(canon, textureManager.spriteshootereen.getPosition());

                if(spriteVisiblecanon)
                window.draw(canon.arrow);

                
                healthBar_een.updatePosition(sf::Vector2f(snel.spriterobottwee.getPosition()));
                healthBar_twee.updatePosition(sf::Vector2f(traag.spriterobottwee.getPosition()));
                healthBar_drie.updatePosition(sf::Vector2f(snelxtraagy.spriterobottwee.getPosition()));
                healthBar_vier.updatePosition(sf::Vector2f(traagxsnely.spriterobottwee.getPosition()));

                redhealthBar_een.updatePosition(sf::Vector2f(snel.spriterobottwee.getPosition()));
                redhealthBar_twee.updatePosition(sf::Vector2f(traag.spriterobottwee.getPosition()));
                redhealthBar_drie.updatePosition(sf::Vector2f(snelxtraagy.spriterobottwee.getPosition()));
                redhealthBar_vier.updatePosition(sf::Vector2f(traagxsnely.spriterobottwee.getPosition()));

                if (canon.arrow.getGlobalBounds().intersects(traag.spriterobottwee.getGlobalBounds()))
                {
                    redhealthBar_twee.applyDamage();
                }

                window.draw(healthBar_een.bar);
                window.draw(healthBar_twee.bar);
                window.draw(healthBar_drie.bar);
                window.draw(healthBar_vier.bar); 

                window.draw(redhealthBar_een.bar);
                window.draw(redhealthBar_twee.bar);
                window.draw(redhealthBar_drie.bar);
                window.draw(redhealthBar_vier.bar);
              

            //}
            }
            window.display();
        }
    }
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(1180, 720), "My Program");
    Game game;
    game.run(window);

    return 0;
}

//getcurrenthealth als die kleiner is dan 0 dan manneke verdwijnen en schieten op volgend
