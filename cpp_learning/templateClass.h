#ifndef _TEMPLATECLASS_H_
#define _TEMPLATECLASS_H_
 
// テンプレートクラスの実装はヘッダファイルにする
template<typename T> class CCalc{
private:
    T m_n1;
    T m_n2;
public:
    inline void set(const T n1, const T n2) 
    { m_n1 = n1; m_n2 = n2; };  //  引数のセット
    
    // inlineを使う場合もヘッダファイルに記述
    // セッター・ゲッターでよく使う
    inline T add() const{
        return m_n1 + m_n2;
    }               //  計算結果
};
 
#endif // _CALC_H_