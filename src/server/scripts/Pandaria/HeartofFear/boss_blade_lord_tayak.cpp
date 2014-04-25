#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "heart_of_fear.h"

enum Yells
{
};

enum Spells
{
};

enum Events
{
};

class boss_blade_lord_tayak : public CreatureScript
{
    public:
        boss_blade_lord_tayak() : CreatureScript("boss_blade_lord_tayak") { }

        struct boss_blade_lord_tayakAI : public BossAI
        {
            boss_blade_lord_tayakAI(Creature* creature) : BossAI(creature, DATA_BLADE_LORD_TAYAK)
            {
            }

            void Reset()
            {
            }

            void EnterCombat(Unit* /*who*/)
            {
            }

            void JustDied(Unit* /*killer*/)
            {
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
                /*
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        default:
                            break;
                    }
                }
                */

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_blade_lord_tayakAI(creature);
        }
};

void AddSC_boss_blade_lord_tayak()
{
    new boss_blade_lord_tayak();
}
