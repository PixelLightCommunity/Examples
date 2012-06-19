//[-------------------------------------------------------]
//[ Header                                                ]
//[-------------------------------------------------------]
#include "Application.h"


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
using namespace PLCore;
using namespace PLRenderer;
using namespace PLScene;
using namespace PLInput;


//[-------------------------------------------------------]
//[ RTTI interface                                        ]
//[-------------------------------------------------------]
pl_implement_class(Application)


//[-------------------------------------------------------]
//[ Functions		                                      ]
//[-------------------------------------------------------]
Application::Application(Frontend &cFrontend) : EngineApplication(cFrontend),
	SlotOnControlEvent(this),
	m_pGui(nullptr)
{
}


Application::~Application()
{
	if (m_pGui) Berkelium::destroy(); // required
}


void Application::OnInit()
{
	EngineApplication::OnInit();

	Controller *pController = reinterpret_cast<Controller*>(EngineApplication::GetInputController());
	if (pController)
	{
		pController->SignalOnControl.Connect(SlotOnControlEvent);
	}

	const Class *pClass = ClassManager::GetInstance()->GetClass("PLBerkelium::Gui");
	if (pClass)
	{
		m_pGui = (PLBerkelium::Gui*)pClass->Create();

		m_pGui->SetRenderers(GetRenderer(), GetSceneRendererTool().GetSceneRenderer()); // required
		m_pGui->ConnectEventUpdate(GetSceneContext()); // required

		m_pGui->ConnectController(pController); // optional but recommended
		pGui->SetMousePointerVisible(true); // optional
		m_pGui->AddWindow("windows1", true, "http://dev.pixellight.org/forum/", 1024, 512, 32, 32); // optional
		m_pGui->GetWindow("windows1")->SetToolTipEnabled(true); // optional
	}
}


void Application::OnStop()
{
	EngineApplication::OnStop();

	if (m_pGui) m_pGui->DestroyInstance(); // required
}


void Application::OnControlEvent(Control &cControl)
{
	if (cControl.GetType() == ControlButton && reinterpret_cast<Button&>(cControl).IsHit())
	{
		if (cControl.GetName() == "KeyboardEscape")
		{
			EngineApplication::Exit(0);
		}
	}
}