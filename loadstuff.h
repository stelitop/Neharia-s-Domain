#ifndef LOADSTUFF_H_INCLUDED
#define LOADSTUFF_H_INCLUDED

class Attributes
{
public:
    int atk;
    int hp;
    int mana;
    int armor;

};

void loading_error (string name)
{
    cout<<"The following files were unable to run :"<<endl;
    cout<<name<<endl;
}

class weapon
{
public:
    int amountOwned;
    string name;
    string rarity;
    Sprite texture;
    Attributes attributes;
    bool isPurchasable=true;
    bool isCraftable=true;
    int PurchasePrice=0;
    pair<string,int> CraftRecipe[1001];
    int CraftAmount=0;

    void loadFromFile (string filename)
    {
        string text="";
        ifstream file;
        //file.open(filename);
        file.open(filename);
        string x;
        while (getline(file, x))
        {
            text+=x+'\n';
        }
        if (text.size() == 0)
        {
            loading_error(filename);
        }
        for (int i=0;i<text.size();i++)
        {
            if (text.substr(i,8) == "<weapon>")
            {
                i+=8;
                for (;text.substr(i,9) != "</weapon>";i++)
                {
                    if (text.substr(i,6) == "<name>")
                    {
                        string WPNname="";
                        i+=6;
                        for (;text.substr(i,7) != "</name>";i++)
                        {
                            WPNname+=text[i];
                        }
                        i+=7;
                        name = WPNname;
                    }
                    if (text.substr(i,9) == "<texture>")
                    {
                        string WPNtexture="";
                        i+=9;
                        for (;text.substr(i,10) != "</texture>";i++)
                        {
                            WPNtexture+=text[i];
                        }
                        Texture x;
                        x.loadFromFile(WPNtexture);
                        texture.setTexture(x);
                        i+=10;
                    }
                    if (text.substr(i,8) == "<rarity>")
                    {
                        string WPNrarity="";
                        i+=8;
                        for (;text.substr(i,9) != "</rarity>";i++)
                        {
                            WPNrarity+=text[i];
                        }
                        i+=9;
                        rarity = WPNrarity;
                    }
                    if (text.substr(i,14) == "<purchasable/>")
                    {
                        i+=14;
                        isPurchasable = true;
                    }
                    if (text.substr(i,18) == "<not_purchasable/>")
                    {
                        i+=18;
                        isPurchasable = false;
                    }
                    if (text.substr(i,12) == "<craftable/>")
                    {
                        i+=12;
                        isCraftable = true;
                    }
                    if (text.substr(i,16) == "<not_craftable/>")
                    {
                        i+=16;
                        isCraftable = false;
                    }
                    if (text.substr(i,12) == "<attributes>")
                    {
                        i+=12;
                        for (;text.substr(i,13) != "</attributes>";i++)
                        {
                            if (text.substr(i,5) == "<atk>")
                            {
                                i+=5;
                                int num=0;
                                for (;text.substr(i,6) != "</atk>";i++)
                                {
                                    num = num*10 + text[i]-'0';
                                }
                                attributes.atk=num;
                                i+6;
                            }

                            if (text.substr(i,4) == "<hp>")
                            {
                                i+=4;
                                int num=0;
                                for (;text.substr(i,5) != "</hp>";i++)
                                {
                                    num = num*10 + text[i]-'0';
                                }
                                attributes.hp=num;
                                i+5;
                            }

                        }
                    }

                }
            }
        }
    }
};

#endif // LOADSTUFF_H_INCLUDED
