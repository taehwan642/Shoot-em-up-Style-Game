#pragma once
#include "Types.h"
#include "Node.h"

class Renderer : public Singleton<Renderer>
{
public:
	void AddRenderTarget(Node* node);
	void RemoveRenderTarget(Node* node);
	void Render();
private:
	//이건뭐하는용도임? 정확히 얘가 어떻게 뭐랑 뭘 하는지 알려줭
	list<Node*> _rendertargets;
	//왜스태틱을붙임?
	static bool Comp(Node* a,Node* b);
};

