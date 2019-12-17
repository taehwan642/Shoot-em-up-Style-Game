#include "DXUT.h"
#include "Renderer.h"

void Renderer::AddRenderTarget(Node* node)
{
	if (find(_rendertargets.begin(), _rendertargets.end(), node) != _rendertargets.end())
		return;
	_rendertargets.push_back(node);
	_rendertargets.sort(Comp);
}

void Renderer::RemoveRenderTarget(Node* node)
{
	_rendertargets.remove(node);
}

void Renderer::Render()
{
	//??
	for (auto it : _rendertargets)
	{
		it->Draw();
		it->Update();
	}
}

bool Renderer::Comp(Node* a, Node* b)
{
	//?? a�� b���Ǵ� ��,���?"?
	return (a->_layer < b->_layer);
}
