#pragma once

#include "Macro.h"
#include "Color.h"
#include "Shader.h"

#include <memory>
#include <unordered_map>
#include <d3d11.h>

class Window;
class Texture2D;
class Font;


/**
 * @brief ������ ���� ó���� �����մϴ�.
 * 
 * @note �� Ŭ������ �̱������� ����� �߰��ϸ� �ٷ� ����� �� �ֽ��ϴ�.
 */
class RenderManager
{
public:
	/**
	 * @brief ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(RenderManager);


	/**
	 * @brief RenderManager�� �ν��Ͻ��� ����ϴ�.
	 * 
	 * @return RenderManager�� �ν��Ͻ� �����ڸ� ��ȯ�մϴ�.
	 */
	static RenderManager& Get()
	{
		static RenderManager Instance;
		return Instance;
	}


	/**
	 * @brief RenderManager�� ��������� �ʱ�ȭ�մϴ�.
	 * 
	 * @param MainWindow ������ ����� �Ǵ� ���� �������� �������Դϴ�.
	 * 
	 * @throws ���� ���ҽ� ������ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	void Setup(Window* MainWindow);


	/**
	 * @brief RenderManager�� ���� ��Ҹ� ��������� �����մϴ�.
	 */
	void Cleanup();


	/**
	 * @brief ���ҽ��� ����� ���÷��� ������� ����� �����ϴ� �� ����ϴ� ����̽��� ����ϴ�.
	 * 
	 * @return ����̽��� �����͸� ��ȯ�մϴ�.
	 */
	ID3D11Device* GetDevice() { return Device_; }


	/**
	 * @brief ����̽��� ������ ���ҽ��� ����Ͽ� ���������� ���¸� �����ϰ� ������ ����� �����ϴ� �� ����ϴ� ���ؽ�Ʈ�� ����ϴ�.
	 * 
	 * @return ���ؽ�Ʈ�� �����͸� ��ȯ�մϴ�.
	 */
	ID3D11DeviceContext* GetContext() { return Context_; }


	/**
	 * @brief ������� ũ�⸦ ����ϴ�.
	 * 
	 * @param Width[out] �������� ���� ũ���Դϴ�.
	 * @param Height[out] �������� ���� ũ���Դϴ�. 
	 */
	void GetBackBufferSize(float& Width, float& Height);


	/**
	 * @brief ���� ���� ���ҽ��� ũ�⸦ �����մϴ�.
	 * 
	 * @throws ������ ũ�� ���濡 �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	void Resize();


	/**
	 * @brief ������������ �� ��Ʈ�� �����մϴ�.
	 * 
	 * @param TopLeftX �� ��Ʈ ���� ����� X��ǥ�Դϴ�.
	 * @param TopLeftY �� ��Ʈ ���� ����� Y��ǥ�Դϴ�.
	 * @param Width �� ��Ʈ�� ���� ũ���Դϴ�.
	 * @param Height �� ��Ʈ�� ���� ũ���Դϴ�.
	 * @param MinDepth �� ��Ʈ�� �ּ� �����Դϴ�. �⺻ ���� 0.0 �Դϴ�.
	 * @param MaxDepth �� ��Ʈ�� �ִ� �����Դϴ�. �⺻ ���� 1.0 �Դϴ�.
	 */
	void SetViewport(float TopLeftX, float TopLeftY, float Width, float Height, float MinDepth = 0.0f, float MaxDepth = 1.0f);


	/**
	 * @brief Z ���� Ȱ��ȭ ���θ� �����մϴ�.
	 * 
	 * @param bIsEnable Z ���� Ȱ��ȭ �����Դϴ�.
	 */
	void SetDepthBuffer(bool bIsEnable);


	/**
	 * @brief ���� ���� Ȱ��ȭ ���θ� �����մϴ�.
	 * 
	 * @param bIsEnable ���� ���� Ȱ��ȭ �����Դϴ�.
	 */
	void SetAlphaBlend(bool bIsEnable);


	/**
	 * @brief ä�� ��� Ȱ��ȭ ���θ� �����մϴ�.
	 * 
	 * @note ��Ȱ��ȭ ������ ��� ���̾� ������ ���� �����˴ϴ�.
	 * 
	 * @brief bIsEnble ä�� ��� Ȱ��ȭ �����Դϴ�.
	 */
	void SetFillMode(bool bIsEnable);


	/**
	 * @brief �� ���۸� �ʱ�ȭ�մϴ�.
	 * 
	 * @param Color �ʱ�ȭ �� �����Դϴ�.
	 * @param Depth ���� ������ �ʱ�ȭ �� ���Դϴ�. �⺻ ���� 1.0 �Դϴ�.
	 * @param Stencil ���ٽ� ������ �ʱ�ȭ �� ���Դϴ�. �⺻ ���� 0�Դϴ�.
	 */
	void Clear(const LinearColor& Color, float Depth = 1.0f, uint8_t Stencil = 0);


	/**
	 * @brief �� ���ۿ� ����Ʈ ���۸� ��ȯ�մϴ�.
	 * 
	 * @see https://learn.microsoft.com/en-us/windows/win32/api/dxgi/nf-dxgi-idxgiswapchain-present
	 * 
	 * @param bIsVSync ���� ����ȭ ���θ� Ȯ���մϴ�. �⺻������ ���� ����ȭ ó���մϴ�.
	 * 
	 * @throws �� ���ۿ� ����Ʈ ������ ��ȯ�� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	void Present(bool bIsVSync = true);


	/**
	 * @brief ȭ�鿡 2D ���� �׸��ϴ�.
	 * 
	 * @param Position ���� ��ġ�Դϴ�.
	 * @param Color ���� �����Դϴ�.
	 */
	void DrawPoint2D(const Vec2f& Position, const LinearColor& Color);


	/**
	 * @brief ȭ�鿡 2D ���� �׸��ϴ�.
	 * 
	 * @param PositionFrom ���� �������Դϴ�.
	 * @param ColorFrom ���� ������ �����Դϴ�.
	 * @param PositionTo ���� �����Դϴ�.
	 * @param ColorTo ���� ���� �����Դϴ�.
	 */
	void DrawLine2D(
		const Vec2f& PositionFrom, const LinearColor& ColorFrom,
		const Vec2f& PositionTo, const LinearColor& ColorTo
	);


	/**
	 * @brief ȭ�鿡 2D ä�� �ﰢ���� �׸��ϴ�.
	 * 
	 * @param PositionFrom �ﰢ�� ������ �������Դϴ�.
	 * @param ColorFrom �ﰢ�� ������ ������ �����Դϴ�.
	 * @param PositionBy �ﰢ�� ������ �߰����Դϴ�.
	 * @param ColorBy �ﰢ�� ������ �߰��� �����Դϴ�.
	 * @param PositionTo �ﰢ�� ������ �����Դϴ�.
	 * @param ColorTo �ﰢ�� ������ ���� �����Դϴ�.
	 */
	void DrawFillTriangle2D(
		const Vec2f& PositionFrom, const LinearColor& ColorFrom,
		const Vec2f& PositionBy, const LinearColor& ColorBy,
		const Vec2f& PositionTo, const LinearColor& ColorTo
	);


	/**
	 * @brief ȭ�鿡 2D ���̾� ������ �ﰢ���� �׸��ϴ�.
	 *
	 * @param PositionFrom �ﰢ�� ������ �������Դϴ�.
	 * @param ColorFrom �ﰢ�� ������ ������ �����Դϴ�.
	 * @param PositionBy �ﰢ�� ������ �߰����Դϴ�.
	 * @param ColorBy �ﰢ�� ������ �߰��� �����Դϴ�.
	 * @param PositionTo �ﰢ�� ������ �����Դϴ�.
	 * @param ColorTo �ﰢ�� ������ ���� �����Դϴ�.
	 */
	void DrawWireframeTriangle2D(
		const Vec2f& PositionFrom, const LinearColor& ColorFrom,
		const Vec2f& PositionBy, const LinearColor& ColorBy,
		const Vec2f& PositionTo, const LinearColor& ColorTo
	);


	/**
	 * @brief ȭ�鿡 2D ä�� �簢���� �׸��ϴ�.
	 * 
	 * @param PositionFrom �ﰢ�� ������ �������Դϴ�.
	 * @param ColorFrom �ﰢ�� ������ ������ �����Դϴ�.
	 * @param PositionBy0 �ﰢ�� ������ �߰����Դϴ�.
	 * @param ColorBy0 �ﰢ�� ������ �߰��� �����Դϴ�.
	 * @param PositionBy1 �ﰢ�� ������ �߰����Դϴ�.
	 * @param ColorBy1 �ﰢ�� ������ �߰��� �����Դϴ�.
	 * @param PositionTo �ﰢ�� ������ �����Դϴ�.
	 * @param ColorTo �ﰢ�� ������ ���� �����Դϴ�.
	 */
	void DrawFillQuad2D(
		const Vec2f& PositionFrom, const LinearColor& ColorFrom,
		const Vec2f& PositionBy0, const LinearColor& ColorBy0,
		const Vec2f& PositionBy1, const LinearColor& ColorBy1,
		const Vec2f& PositionTo, const LinearColor& ColorTo
	);


	/**
	 * @brief ȭ�鿡 2D ���̾� ������ �簢���� �׸��ϴ�.
	 *
	 * @param PositionFrom �ﰢ�� ������ �������Դϴ�.
	 * @param ColorFrom �ﰢ�� ������ ������ �����Դϴ�.
	 * @param PositionBy0 �ﰢ�� ������ �߰����Դϴ�.
	 * @param ColorBy0 �ﰢ�� ������ �߰��� �����Դϴ�.
	 * @param PositionBy1 �ﰢ�� ������ �߰����Դϴ�.
	 * @param ColorBy1 �ﰢ�� ������ �߰��� �����Դϴ�.
	 * @param PositionTo �ﰢ�� ������ �����Դϴ�.
	 * @param ColorTo �ﰢ�� ������ ���� �����Դϴ�.
	 */
	void DrawWireframeQuad2D(
		const Vec2f& PositionFrom, const LinearColor& ColorFrom,
		const Vec2f& PositionBy0, const LinearColor& ColorBy0,
		const Vec2f& PositionBy1, const LinearColor& ColorBy1,
		const Vec2f& PositionTo, const LinearColor& ColorTo
	);


	/**
	 * @brief ȭ�鿡 2D �ؽ�ó�� �׸��ϴ�.
	 * 
	 * @ntoe ȸ������ ���� �����Դϴ�.
	 * 
	 * @param Texture ������ ����� �Ǵ� 2D �ؽ�ó�Դϴ�.
	 * @param Center �ؽ�ó�� �߽� ��ǥ�Դϴ�.
	 * @param Width �ؽ�ó�� ���� ũ���Դϴ�.
	 * @param Height �ؽ�ó�� ���� ũ���Դϴ�.
	 * @param Rotate �ؽ�ó�� ȸ�� �����Դϴ�. �⺻ ���� 0.0�Դϴ�.
	 */
	void DrawTexture2D(Texture2D& Texture, const Vec2f& Center, float Width, float Height, float Rotate = 0.0f);


	/**
	 * @brief ȭ�鿡 2D �ؽ�Ʈ�� �׸��ϴ�.
	 * 
	 * @param FontResource �ؽ�Ʈ�� �������� �� ������ ��Ʈ ���ҽ��Դϴ�.
	 * @param Text �������� �ؽ�Ʈ�Դϴ�.
	 * @param Center �ؽ�ó�� �߽� ��ǥ�Դϴ�.
	 * @param Color �ؽ�Ʈ�� �����Դϴ�.
	 */
	void DrawText2D(Font& FontResource, const std::wstring& Text, const Vec2f& Center, const LinearColor& Color);


private:
	/**
	 * @brief �׷��� ���� ó���� �����ϴ� Ŭ������ �������Դϴ�.
	 * 
	 * @note �����ڴ� �ƹ��� ���۵� �������� �ʽ��ϴ�.
	 */
	RenderManager() = default;


	/**
	 * @brief �׷��� ���� ���ҽ��� �����ϴ� ���� �Ҹ����Դϴ�.
	 */
	virtual ~RenderManager();


	/**
	 * @brief ����̽� �� ���ؽ�Ʈ�� �����մϴ�.
	 * 
	 * @param WindowHandle ����� �Ǵ� ������ �ڵ��Դϴ�.
	 * 
	 * @return ����̽� �� ���ؽ�Ʈ�� ���� ����� ��ȯ�մϴ�. �����ߴٸ� S_OK, �׷��� �ʴٸ� �� �̿��� ���� ��ȯ�մϴ�.
	 */
	HRESULT CreateDeviceAndContext(HWND WindowHandle);


	/**
	 * @brief ���� ü���� �����մϴ�.
	 * 
	 * @param WindowHandle ����� �Ǵ� ������ �ڵ��Դϴ�.
	 * 
	 * @return ���� ü�� ���� ����� ��ȯ�մϴ�. �����ߴٸ� S_OK, �׷��� �ʴٸ� �� �̿��� ���� ��ȯ�մϴ�.
	 */
	HRESULT CreateSwapChain(HWND WindowHandle);


	/**
	 * @brief ���� Ÿ�� �並 �����մϴ�.
	 * 
	 * @return ���� Ÿ�� �� ���� ����� ��ȯ�մϴ�. �����ߴٸ� S_OK, �׷��� �ʴٸ� �� �̿��� ���� ��ȯ�մϴ�.
	 */
	HRESULT CreateRenderTargetView();


	/**
	 * @brief ���� ���ٽ� �並 �����մϴ�.
	 * 
	 * @return ���� ���ٽ� ���� ���� ����� ��ȯ�մϴ�. �����ߴٸ� S_OK, �׷��� �ʴٸ� �� �̿��� ���� ��ȯ�մϴ�.
	 */
	HRESULT CreateDepthStencilView();


	/**
	 * @brief ���� ���ٽ� ���¸� �����մϴ�.
	 * 
	 * @param DepthStencilState ������ ���� ���ٽ� ���¸� ������ �������Դϴ�.
	 * @param bIsEnableDepth ���� ���� Ȱ��ȭ �����Դϴ�.
	 * @param bIsEnableStencil ���ٽ� ���� Ȱ��ȭ �����Դϴ�.
	 * 
	 * @return ���� ���ٽ� ���� ���� ����� ��ȯ�մϴ�. �����ߴٸ� S_OK, �׷��� �ʴٸ� �� �̿��� ���� ��ȯ�մϴ�.
	 */
	HRESULT CreateDepthStencilState(ID3D11DepthStencilState** DepthStencilState, bool bIsEnableDepth, bool bIsEnableStencil);


	/**
	 * @brief ������ ���� ���� ���¸� �����մϴ�.
	 * 
	 * @param BlendState ������ ���� ���¸� ������ �������Դϴ�.
	 * @param bIsEnable ���� ���� Ȱ��ȭ �����Դϴ�.
	 * 
	 * @return ���� ���� ���� ����� ��ȯ�մϴ�. �����ߴٸ� S_OK, �׷��� �ʴٸ� �� �̿��� ���� ��ȯ�մϴ�.
	 */
	HRESULT CreateBlendState(ID3D11BlendState** BlendState, bool bIsEnable);


	/**
	 * @brief �����Ͷ����� ���¸� �����մϴ�.
	 * 
	 * @param RasterizerState ������ �����Ͷ����� ���¸� ������ �������Դϴ�.
	 * @param bIsEnableCull �ø��� ���� �����Դϴ�.
	 * @param bIsEnableFill ������ �� ä�� ��� ���� �����Դϴ�.
	 * 
	 * @return �����Ͷ����� ���� ���� ����� ��ȯ�մϴ�. �����ߴٸ� S_OK, �׷��� �ʴٸ� �� �̿��� ���� ��ȯ�մϴ�.
	 */
	HRESULT CreateRasterizerState(ID3D11RasterizerState** RasterizerState, bool bIsEnableCull, bool bIsEnableFill);


private:
	/**
	 * @brief �������� ����Ǵ� ���� �������Դϴ�.
	 */
	Window* MainWindow_ = nullptr;


	/**
	 * @brief ����̹� Ÿ���Դϴ�.
	 *
	 * @see https://learn.microsoft.com/en-us/windows/win32/api/d3dcommon/ne-d3dcommon-d3d_driver_type
	 */
	D3D_DRIVER_TYPE	DriverType_ = D3D_DRIVER_TYPE_NULL;


	/**
	 * @brief ����̽��� ������� �ϴ� ����Դϴ�.
	 *
	 * @see https://learn.microsoft.com/en-us/windows/win32/api/d3dcommon/ne-d3dcommon-d3d_feature_level
	 */
	D3D_FEATURE_LEVEL FeatureLevel_ = D3D_FEATURE_LEVEL_11_0;


	/**
	 * @brief ���ҽ��� ����� ���÷��� ������� ����� �����ϴ� �� ����մϴ�.
	 *
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/direct3d11/overviews-direct3d-11-devices-intro
	 */
	ID3D11Device* Device_ = nullptr;


	/**
	 * @brief ����̽��� ������ ���ҽ��� ����Ͽ� ���������� ���¸� �����ϰ� ������ ����� �����ϴ� �� ����մϴ�.
	 *
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/direct3d11/overviews-direct3d-11-devices-intro
	 */
	ID3D11DeviceContext* Context_ = nullptr;


	/**
	 * @brief �������� �����͸� ��¿� ǥ���ϱ� ���� �����մϴ�.
	 *
	 * @see https://learn.microsoft.com/en-us/windows/win32/api/dxgi/nn-dxgi-idxgiswapchain
	 */
	IDXGISwapChain* SwapChain_ = nullptr;


	/**
	 * @brief ������ �� ������ �� �� �ִ� ���ҽ��Դϴ�.
	 *
	 * @see https://learn.microsoft.com/en-us/windows/win32/api/d3d11/nn-d3d11-id3d11rendertargetview
	 */
	ID3D11RenderTargetView* RenderTargetView_ = nullptr;


	/**
	 * @brief ���� ���ٽ� ���� ���ҽ��Դϴ�.
	 * 
	 * @see https://learn.microsoft.com/en-us/windows/win32/api/d3d11/nn-d3d11-id3d11texture2d
	 */
	ID3D11Texture2D* DepthStencilBuffer_ = nullptr;


	/**
	 * @brief ���� ���ٽ� �� ���ҽ��Դϴ�.
	 * 
	 * @see https://learn.microsoft.com/en-us/windows/win32/api/d3d11/nn-d3d11-id3d11depthstencilview
	 */
	ID3D11DepthStencilView* DepthStencilView_ = nullptr;


	/**
	 * @brief ������ �� ����� ���� ���ٽ� �����Դϴ�.
	 */
	std::unordered_map<std::string, ID3D11DepthStencilState*> DepthStencilState_;


	/**
	 * @brief ������ �� ����� ���� �����Դϴ�.
	 */
	std::unordered_map<std::string, ID3D11BlendState*> BlendState_;


	/**
	 * @brief ������ �� ����� �����Ͷ����� �����Դϴ�.
	 */
	std::unordered_map<std::string, ID3D11RasterizerState*> RasterizerState_;


	/**
	 * @brief ������ �� ����� ���̴��Դϴ�.
	 */
	std::unordered_map<std::string, std::unique_ptr<Shader>> Shader_;
};