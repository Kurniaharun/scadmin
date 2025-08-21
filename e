--// UI Script Premium Key System by Laww (Premium Only - No Free Features)

--// Services
local Players = game:GetService("Players")
local player = Players.LocalPlayer
local CoreGui = game:GetService("CoreGui")

-- Remove existing UI jika ada
if CoreGui:FindFirstChild("PremiumKeySystemUI") then
    CoreGui.PremiumKeySystemUI:Destroy()
end

--// ScreenGui
local gui = Instance.new("ScreenGui", CoreGui)
gui.Name = "PremiumKeySystemUI"

--// Frame utama
local mainFrame = Instance.new("Frame", gui)
mainFrame.Size = UDim2.new(0,450,0,300)
mainFrame.Position = UDim2.new(0.5,0,0.5,0)
mainFrame.AnchorPoint = Vector2.new(0.5,0.5)
mainFrame.BackgroundColor3 = Color3.fromRGB(15,15,15)
mainFrame.BorderSizePixel = 0
mainFrame.ClipsDescendants = true
mainFrame.Visible = true

-- Corner
local UICorner = Instance.new("UICorner", mainFrame)
UICorner.CornerRadius = UDim.new(0,15)

-- Header
local header = Instance.new("TextLabel", mainFrame)
header.Size = UDim2.new(1,0,0,50)
header.BackgroundColor3 = Color3.fromRGB(220,20,60)
header.Text = "🔑 PREMIUM KEY SYSTEM 🔑"
header.TextColor3 = Color3.fromRGB(255,255,255)
header.TextScaled = true
header.Font = Enum.Font.GothamBold
local UICorner2 = Instance.new("UICorner", header)
UICorner2.CornerRadius = UDim.new(0,15)

-- Close Button
local closeBtn = Instance.new("TextButton", mainFrame)
closeBtn.Size = UDim2.new(0,35,0,35)
closeBtn.Position = UDim2.new(1, -45, 0, 7.5)
closeBtn.AnchorPoint = Vector2.new(0,0)
closeBtn.BackgroundColor3 = Color3.fromRGB(255,60,60)
closeBtn.Text = "✕"
closeBtn.TextColor3 = Color3.fromRGB(255,255,255)
closeBtn.TextScaled = true
closeBtn.Font = Enum.Font.GothamBold
closeBtn.ZIndex = 2
local closeUICorner = Instance.new("UICorner", closeBtn)
closeUICorner.CornerRadius = UDim.new(0, 10)

closeBtn.MouseButton1Click:Connect(function()
    gui:Destroy()
end)

-- Premium Notice
local premiumNotice = Instance.new("TextLabel", mainFrame)
premiumNotice.Size = UDim2.new(0.9,0,0,40)
premiumNotice.Position = UDim2.new(0.05,0,0.2,0)
premiumNotice.Text = "⭐ PREMIUM ACCESS REQUIRED ⭐"
premiumNotice.TextColor3 = Color3.fromRGB(255,215,0)
premiumNotice.TextScaled = true
premiumNotice.Font = Enum.Font.GothamBold
premiumNotice.BackgroundTransparency = 1

-- Input Key
local keyBox = Instance.new("TextBox", mainFrame)
keyBox.Size = UDim2.new(0.85,0,0,45)
keyBox.Position = UDim2.new(0.075,0,0.35,0)
keyBox.PlaceholderText = "Enter your premium key..."
keyBox.Text = ""
keyBox.Font = Enum.Font.Gotham
keyBox.TextScaled = true
keyBox.TextColor3 = Color3.fromRGB(255,255,255)
keyBox.BackgroundColor3 = Color3.fromRGB(25,25,25)
local UICorner3 = Instance.new("UICorner", keyBox)
UICorner3.CornerRadius = UDim.new(0,10)

-- Tombol Submit Key
local submitBtn = Instance.new("TextButton", mainFrame)
submitBtn.Size = UDim2.new(0.85,0,0,45)
submitBtn.Position = UDim2.new(0.075,0,0.52,0)
submitBtn.Text = "🚀 ACTIVATE PREMIUM"
submitBtn.Font = Enum.Font.GothamBold
submitBtn.TextScaled = true
submitBtn.TextColor3 = Color3.fromRGB(255,255,255)
submitBtn.BackgroundColor3 = Color3.fromRGB(0,150,255)
local UICorner4 = Instance.new("UICorner", submitBtn)
UICorner4.CornerRadius = UDim.new(0,10)

-- Tombol Buy Premium
local buyBtn = Instance.new("TextButton", mainFrame)
buyBtn.Size = UDim2.new(0.85,0,0,50)
buyBtn.Position = UDim2.new(0.075,0,0.72,0)
buyBtn.Text = "💎 BUY PREMIUM KEY"
buyBtn.Font = Enum.Font.GothamBold
buyBtn.TextScaled = true
buyBtn.TextColor3 = Color3.fromRGB(255,255,255)
buyBtn.BackgroundColor3 = Color3.fromRGB(220,20,60)
local UICorner6 = Instance.new("UICorner", buyBtn)
UICorner6.CornerRadius = UDim.new(0,12)

-- Frame Premium Purchase
local premiumFrame = Instance.new("Frame", gui)
premiumFrame.Size = UDim2.new(0,500,0,350)
premiumFrame.Position = UDim2.new(0.5,0,0.5,0)
premiumFrame.AnchorPoint = Vector2.new(0.5,0.5)
premiumFrame.BackgroundColor3 = Color3.fromRGB(15,15,15)
premiumFrame.Visible = false
local UICorner7 = Instance.new("UICorner", premiumFrame)
UICorner7.CornerRadius = UDim.new(0,15)

-- Premium Frame Header
local premTitle = Instance.new("TextLabel", premiumFrame)
premTitle.Size = UDim2.new(1,0,0,60)
premTitle.BackgroundColor3 = Color3.fromRGB(220,20,60)
premTitle.Text = "💎 BUY PREMIUM ACCESS 💎"
premTitle.TextColor3 = Color3.fromRGB(255,255,255)
premTitle.TextScaled = true
premTitle.Font = Enum.Font.GothamBold
local UICorner8 = Instance.new("UICorner", premTitle)
UICorner8.CornerRadius = UDim.new(0,15)

-- Back Button
local backBtn = Instance.new("TextButton", premiumFrame)
backBtn.Size = UDim2.new(0,35,0,35)
backBtn.Position = UDim2.new(1, -45, 0, 12.5)
backBtn.BackgroundColor3 = Color3.fromRGB(255,60,60)
backBtn.Text = "←"
backBtn.TextColor3 = Color3.fromRGB(255,255,255)
backBtn.TextScaled = true
backBtn.Font = Enum.Font.GothamBold
backBtn.ZIndex = 2
local backUICorner = Instance.new("UICorner", backBtn)
backUICorner.CornerRadius = UDim.new(0, 10)

-- Premium Benefits
local benefitsLabel = Instance.new("TextLabel", premiumFrame)
benefitsLabel.Size = UDim2.new(0.9,0,0,80)
benefitsLabel.Position = UDim2.new(0.05,0,0.2,0)
benefitsLabel.Text = "✅ Unlimited Access\n✅ All Premium Features\n✅ 24/7 Support\n✅ Lifetime Updates"
benefitsLabel.TextColor3 = Color3.fromRGB(0,255,127)
benefitsLabel.TextScaled = true
benefitsLabel.Font = Enum.Font.Gotham
benefitsLabel.BackgroundTransparency = 1

-- Kontak WA
local wa = Instance.new("TextButton", premiumFrame)
wa.Size = UDim2.new(0.9,0,0,50)
wa.Position = UDim2.new(0.05,0,0.52,0)
wa.Text = "📱 WHATSAPP: +6285351187520 (Click to Copy)"
wa.Font = Enum.Font.GothamBold
wa.TextScaled = true
wa.TextColor3 = Color3.fromRGB(255,255,255)
wa.BackgroundColor3 = Color3.fromRGB(37,211,102)
local UICorner9 = Instance.new("UICorner", wa)
UICorner9.CornerRadius = UDim.new(0,12)

-- Kontak Discord
local disc = Instance.new("TextButton", premiumFrame)
disc.Size = UDim2.new(0.9,0,0,50)
disc.Position = UDim2.new(0.05,0,0.72,0)
disc.Text = "💬 DISCORD: @lawwtod (Click to Copy)"
disc.Font = Enum.Font.GothamBold
disc.TextScaled = true
disc.TextColor3 = Color3.fromRGB(255,255,255)
disc.BackgroundColor3 = Color3.fromRGB(88,101,242)
local UICorner10 = Instance.new("UICorner", disc)
UICorner10.CornerRadius = UDim.new(0,12)

-- Helper: Copy and show 'Copied!' for 1s, then revert
local function copyWithFeedback(btn, text, orig)
    setclipboard(text)
    local old = btn.Text
    btn.Text = orig or "Copied!"
    btn.TextColor3 = Color3.fromRGB(0,255,0)
    btn.AutoButtonColor = false
    task.spawn(function()
        wait(1)
        btn.Text = old
        btn.TextColor3 = Color3.fromRGB(255,255,255)
        btn.AutoButtonColor = true
    end)
end

--// Premium Logic (No Free Features)
wa.MouseButton1Click:Connect(function()
    copyWithFeedback(wa, "+6285351187520", "Contact copied!")
end)

disc.MouseButton1Click:Connect(function()
    copyWithFeedback(disc, "@lawwtod", "Contact copied!")
end)

buyBtn.MouseButton1Click:Connect(function()
    mainFrame.Visible = false
    premiumFrame.Visible = true
end)

backBtn.MouseButton1Click:Connect(function()
    premiumFrame.Visible = false
    mainFrame.Visible = true
end)

submitBtn.MouseButton1Click:Connect(function()
    local key = keyBox.Text
    -- Premium keys only - no free access
    if key == "PREMIUM-LAWW-2024" or key == "VIP-ACCESS-KEY" or key == "ULTIMATE-PREMIUM" then
        loadstring(game:HttpGet("https://pastefy.app/JmGgwxyQ/raw"))()
        gui:Destroy()
    else
        keyBox.Text = "❌ INVALID PREMIUM KEY!"
        keyBox.TextColor3 = Color3.fromRGB(255,100,100)
        task.spawn(function()
            wait(2)
            keyBox.Text = ""
            keyBox.TextColor3 = Color3.fromRGB(255,255,255)
        end)
    end
end)