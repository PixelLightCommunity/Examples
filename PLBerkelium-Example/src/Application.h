#pragma once


//[-------------------------------------------------------]
//[ Includes                                              ]
//[-------------------------------------------------------]
#include <PLCore/System/System.h>
#include <PLCore/System/Console.h>
#include <PLCore/Base/ClassManager.h>
#include <PLCore/Base/Class.h>
#include <PLCore/Base/Func/FuncGenMemPtr.h>
#include <PLEngine/Application/EngineApplication.h>
#include <PLRenderer/Renderer/FontManager.h>
#include <PLRenderer/Renderer/FontTexture.h>
#include <PLRenderer/Renderer/Renderer.h>
#include <PLScene/Compositing/SceneRenderer.h>
#include <PLScene/Compositing/SceneRendererPass.h>
#include <PLScene/Scene/SceneContext.h>
#include <PLInput/Input/Controls/Button.h>
#include <PLInput/Input/Controller.h>
#include <PLInput/Input/Controls/Axis.h>
#include <PLInput/Input/Devices/Device.h>
#include <PLInput/Input/InputManager.h>

#include <PLBerkelium/SRPWindows.h>
#include <PLBerkelium/Gui.h>


//[-------------------------------------------------------]
//[ Classes                                               ]
//[-------------------------------------------------------]
class Application : public PLEngine::EngineApplication {


	//[-------------------------------------------------------]
	//[ RTTI interface                                        ]
	//[-------------------------------------------------------]
	pl_class(pl_rtti_export, Application, "", PLEngine::EngineApplication, "")
		pl_constructor_1(ParameterConstructor, PLCore::Frontend&, "", "")
		pl_slot_1(OnControlEvent, PLInput::Control&, "", "")
	pl_class_end


	public:
		Application(PLCore::Frontend &cFrontend);
		virtual ~Application();

	protected:
		virtual void OnInit() override;
		virtual void OnStop() override;

	private:
		void OnControlEvent(PLInput::Control &cControl);

		PLBerkelium::Gui *m_pGui;


};